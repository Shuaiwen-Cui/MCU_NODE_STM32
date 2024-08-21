/**
  ******************************************************************************
  * @file           : ADXL362.h
  * @brief File for function declarations, macros, and structures. Needed for working with the ADXL362/345 accelerometer.
  ******************************************************************************
  */

#ifndef ADXL362_H
#define ADXL362_H

#include <stdint.h>
#include <stdbool.h>
#include "stm32h7xx_hal.h"


#define ADXLCS_Pin GPIO_PIN_4         /**< Pin for controlling the CS of the ADXL362 accelerometer */
#define ADXLCS_GPIO_Port GPIOA        /**< Port for controlling the CS of the ADXL362 accelerometer */

// Definition of ADXL362 registers
#define ADXL362_DEVID_AD            0x00    /**< Register address for device ID AD */
#define ADXL362_DEVID_MST           0x01    /**< Register address for device ID MST */
#define ADXL362_PARTID              0x02    /**< Register address for part ID */
#define ADXL362_REVID               0x03    /**< Register address for revision ID */
#define ADXL362_XDATA               0x08    /**< Register address for X-axis data */
#define ADXL362_YDATA               0x09    /**< Register address for Y-axis data */
#define ADXL362_ZDATA               0x0A    /**< Register address for Z-axis data */
#define ADXL362_STATUS              0x0B    /**< Register address for device status */
#define ADXL362_FIFO_ENTRIES_L      0x0C    /**< Register address for the lower byte of FIFO data count */
#define ADXL362_FIFO_ENTRIES_H      0x0D    /**< Register address for the upper byte of FIFO data count */
#define ADXL362_XDATA_L             0x0E    /**< Register address for the lower byte of X-axis data */
#define ADXL362_XDATA_H             0x0F    /**< Register address for the upper byte of X-axis data */
#define ADXL362_YDATA_L             0x10    /**< Register address for the lower byte of Y-axis data */
#define ADXL362_YDATA_H             0x11    /**< Register address for the upper byte of Y-axis data */
#define ADXL362_ZDATA_L             0x12    /**< Register address for the lower byte of Z-axis data */
#define ADXL362_ZDATA_H             0x13    /**< Register address for the upper byte of Z-axis data */
#define ADXL362_TEMP_L              0x14    /**< Register address for the lower byte of temperature */
#define ADXL362_TEMP_H              0x15    /**< Register address for the upper byte of temperature */
#define ADXL362_SOFT_RESET          0x1F    /**< Register address for software reset */
#define ADXL362_THRESH_ACT_L        0x20    /**< Register address for the lower byte of activity threshold */
#define ADXL362_THRESH_ACT_H        0x21    /**< Register address for the upper byte of activity threshold */
#define ADXL362_TIME_ACT            0x22    /**< Register address for activity time */
#define ADXL362_THRESH_INACT_L      0x23    /**< Register address for the lower byte of inactivity threshold */
#define ADXL362_THRESH_INACT_H      0x24    /**< Register address for the upper byte of inactivity threshold */
#define ADXL362_TIME_INACT_L        0x25    /**< Register address for the lower byte of inactivity time */
#define ADXL362_TIME_INACT_H        0x26    /**< Register address for the upper byte of inactivity time */
#define ADXL362_ACT_INACT_CTL       0x27    /**< Register address for activity/inactivity control */
#define ADXL362_FIFO_CONTROL        0x28    /**< Register address for FIFO control */
#define ADXL362_FIFO_SAMPLES        0x29    /**< Register address for FIFO sample count */
#define ADXL362_INTMAP1             0x2A    /**< Register address for the first interrupt map */
#define ADXL362_INTMAP2             0x2B    /**< Register address for the second interrupt map */
#define ADXL362_FILTER_CTL          0x2C    /**< Register address for filter control */
#define ADXL362_POWER_CTL           0x2D    /**< Register address for power control */
#define ADXL362_SELF_TEST           0x2E    /**< Register address for self-test */


/**
 * @enum adxlStatus
 * @brief Enumeration of possible statuses for ADXL362 functions
 */
typedef enum {ADXL_OK, ADXL_ERR} adxlStatus;

/**
 * @struct ADXLParams
 * @brief Structure for storing parameters and state of the ADXL362
 */
typedef struct {
  SPI_HandleTypeDef* hspi1; /**< Pointer to the SPI structure */
  DMA_HandleTypeDef* hdma_rx; /**< Pointer to the DMA structure for reception */
  DMA_HandleTypeDef* hdma_tx; /**< Pointer to the DMA structure for transmission */
  uint8_t m_x; /**< X-axis value */
  uint8_t m_y; /**< Y-axis value */
  uint8_t m_z; /**< Z-axis value */
  uint8_t m_ADXL362_THRESH_ACT_status; /**< Status of the activity threshold */
  uint8_t ADXL362_THRESH_INACT_status; /**< Status of the inactivity threshold */
  uint8_t treshold_reg_status; /**< Status of the threshold register */
  uint8_t soft_res_status; /**< Status of the software reset */
} ADXLParams;

adxlStatus ADXL362_Init(SPI_HandleTypeDef* handle, DMA_HandleTypeDef* hdma_rx_ptr, DMA_HandleTypeDef* hdma_tx_ptr);
void ADXL362_ReadXYZ_16(uint16_t* x, uint16_t* y, uint16_t* z);
void ADXL362_ReadXYZ_8(uint8_t* x, uint8_t* y, uint8_t* z);
static void SPI_WriteRegister(uint8_t reg, uint8_t value);
static void SPI_ReadRegister(uint8_t address, uint8_t* buffer, uint8_t numBytes);

#endif /* ADXL362_H */
