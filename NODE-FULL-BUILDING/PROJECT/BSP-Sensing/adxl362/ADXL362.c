/**
  ******************************************************************************
  * @file           : adxl362.c
  * @brief          Implementation of functions for working with the ADXL362 accelerometer.
  * 
  * This file contains the implementation of initialization functions, data reading from the accelerometer,
  * and functions for working with SPI.
  ******************************************************************************
  */

#include "ADXL362.h"

static ADXLParams adxlParams;

volatile bool spiTxComplete = false;
volatile bool spiRxComplete = false;

/**
  * @brief  Initialization of the ADXL362 accelerometer.
  * 
  * @param  handle Pointer to the SPI structure.
  * @param  hdma_rx_ptr Pointer to the DMA structure for reception.
  * @param  hdma_tx_ptr Pointer to the DMA structure for transmission.
  * @retval Initialization status (ADXL_OK or ADXL_ERR).
  */
adxlStatus ADXL362_Init(SPI_HandleTypeDef* handle, DMA_HandleTypeDef* hdma_rx_ptr, DMA_HandleTypeDef* hdma_tx_ptr) {
  
  adxlParams.hspi1 = handle;
  adxlParams.hdma_rx = hdma_rx_ptr;
  adxlParams.hdma_tx = hdma_tx_ptr;
  SPI_WriteRegister(ADXL362_THRESH_ACT_L, 0x00);
  SPI_WriteRegister(ADXL362_TIME_INACT_H, 0x00);
  SPI_WriteRegister(ADXL362_TIME_ACT, 0x05);
  SPI_WriteRegister(ADXL362_ACT_INACT_CTL, 0x00);
  SPI_WriteRegister(ADXL362_FIFO_CONTROL, 0x00); //0x00
  SPI_WriteRegister(ADXL362_FIFO_SAMPLES, 0x80);
  SPI_WriteRegister(ADXL362_INTMAP1, 0x00);
  SPI_WriteRegister(ADXL362_INTMAP2, 0x00);
  SPI_WriteRegister(ADXL362_FILTER_CTL, 0x13);
  SPI_WriteRegister(ADXL362_POWER_CTL, 0x00);

  SPI_WriteRegister(ADXL362_THRESH_ACT_L, 0xFA);
  //SPI_ReadRegister(ADXL362_THRESH_ACT_L, &adxlParams.m_ADXL362_THRESH_ACT_status, 1);
  SPI_WriteRegister(ADXL362_THRESH_INACT_L, 0x96);
  //SPI_ReadRegister(ADXL362_THRESH_INACT_L, &adxlParams.ADXL362_THRESH_INACT_status, 1);
  SPI_WriteRegister(ADXL362_TIME_INACT_L, 0x1E);
  SPI_WriteRegister(ADXL362_ACT_INACT_CTL, 0x3F);
  //SPI_WriteRegister(ADXL362_INTMAP2, 0x00); // ???
  SPI_WriteRegister(ADXL362_POWER_CTL, 0x0A); //0x0A
  return ADXL_OK;
}

/**
  * @brief  Reading the X, Y, Z axis values in 16-bit format.
  * 
  * @param  x Pointer to a variable for storing the X-axis value.
  * @param  y Pointer to a variable for storing the Y-axis value.
  * @param  z Pointer to a variable for storing the Z-axis value.
  */
void ADXL362_ReadXYZ_16(uint16_t* x, uint16_t* y, uint16_t* z) {
  
    uint8_t rawData[6]; // Addresses of the required registers are 0x0E - 0x13 (inclusive), i.e., 6 bytes
    SPI_ReadRegister(ADXL362_XDATA_L, rawData, 6);    
    
    // Since the data for each axis is stored in a 12-bit format, we read 6 registers,
    // resulting in 6 bytes (2 bytes per axis). To output correctly, we shift each odd element of the resulting array
    // by 1 byte to the left and use a logical AND to store the remaining data in our variables, which are 16 bits in size.
    // The output will be 12 bits of information and 4 zeros before the data (0000 101010101010).
    *x = (uint16_t)((rawData[1] << 8) | rawData[0]);
    *y = (uint16_t)((rawData[3] << 8) | rawData[2]);
    *z = (uint16_t)((rawData[5] << 8) | rawData[4]);
  
}

/**
  * @brief  Reading the X, Y, Z axis values in 8-bit format.
  * 
  * @param  x Pointer to a variable for storing the X-axis value.
  * @param  y Pointer to a variable for storing the Y-axis value.
  * @param  z Pointer to a variable for storing the Z-axis value.
  */
void ADXL362_ReadXYZ_8(uint8_t* x, uint8_t* y, uint8_t* z) {
  
  uint8_t rawData[3];
  SPI_ReadRegister(ADXL362_XDATA, rawData, 3);
    
  *x = (uint8_t) rawData[0];
  *y = (uint8_t) rawData[1];
  *z = (uint8_t) rawData[2];
}

/**
  * @brief  Writing a value to the accelerometer register.
  * 
  * @param  address Register address.
  * @param  value Value to write.
  */
static void SPI_WriteRegister(uint8_t address, uint8_t value) {
  
    if (address > 63) // Maximum register address is 62 (0x3E)
        address = 63;
    
    uint8_t data[3];  // Command + Address + Data
    data[0] = 0x0A;  // Command for writing 
    data[1] = address; // Register address
    data[2] = value; // Data to write 
    
    spiTxComplete = false;  
    
    HAL_GPIO_WritePin(ADXLCS_GPIO_Port, ADXLCS_Pin, GPIO_PIN_RESET);  // Disable CS (NSS in case of master) to start sending the command 
    HAL_SPI_Transmit_DMA(adxlParams.hspi1, data, 3); // Writing data to the register
    while (!spiTxComplete) {} // When data transmission via SPI is complete, an interrupt HAL_SPI_TxCpltCallback is triggered, and spiTxComplete is set to true
    HAL_GPIO_WritePin(ADXLCS_GPIO_Port, ADXLCS_Pin, GPIO_PIN_SET);  // Enable CS (NSS in case of master) to end the command transmission 
}

/**
  * @brief  Reading values from the register.
  * 
  * @param  address Register address.
  * @param  buffer Buffer to store the read values.
  * @param  numBytes Number of bytes to read.
  */
static void SPI_ReadRegister(uint8_t address, uint8_t* buffer, uint8_t numBytes) {
  
    if (address > 63)
        address = 63;
    
    uint8_t commandAndAddress[2];
    commandAndAddress[0] = 0x0B;
    commandAndAddress[1] = address;
    
    spiTxComplete = false;
    spiRxComplete = false;
    
    HAL_GPIO_WritePin(ADXLCS_GPIO_Port, ADXLCS_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(adxlParams.hspi1, commandAndAddress, 2); // Sending the read command
    while (!spiTxComplete) {}
    HAL_SPI_Receive_DMA(adxlParams.hspi1, buffer, numBytes);  // Receiving values from the register
    while (!spiRxComplete) {} // When data transmission via SPI is complete, an interrupt HAL_SPI_RxCpltCallback is triggered, and spiRxComplete is set to true
    
    HAL_GPIO_WritePin(ADXLCS_GPIO_Port, ADXLCS_Pin, GPIO_PIN_SET);
}