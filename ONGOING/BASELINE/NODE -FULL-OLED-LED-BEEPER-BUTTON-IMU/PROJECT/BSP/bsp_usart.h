/**
 * @file bsp_usart.h
 * @author SHUAIWEN CUI (shuaiwencui AT gmail DOT com)
 * @brief This is the header file for the bsp_usart.c file
 * @version 1.0
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef _BSP_USART_H_
#define _BSP_USART_H_

/**
 * ! INCLUDES
 */

#include "stm32h7xx_hal.h" // HAL library file declaration, replace it with the corresponding file according to the actual situation
#include <string.h> // Library for string processing
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
//#include "iled.h"
// #include "../tim/tim.h"


/**
 * ! MACROS
 * ! Note that TX_BUF_SIZE and RX_BUF_SIZE are the caps for the TX_BUF and RX_BUF arrays, adjust them accordingly.
 * ! Note for receiving, if you use interrupt mode, the interrupt will only be triggered when the buffer RX_BUF is full, assuming you are using the HAL_UART_RxCpltCallback function.
 */


#define TX_MODE 2 // Define the transmission mode: 0 - blocking mode (not recommended), 1 - interrupt mode (* recommended), and 2 - DMA mode (** recommended) !!! note that mode 2 sometimes does not work, not sure about the reason.
#define RX_MODE 3 // Define the reception mode: 0 - blocking mode (not recommended), 1 - interrupt mode (recommended), and 2 - DMA mode (recommended); 3 - DMA IDLE mode (recommended) (only when IDLE_MODE is enabled)

//IDLE mode means non fixed length of data, the data is received until the idle line is detected
#if RX_MODE >= 3
#define IDLE_MODE 
#endif

#define TX_BUF_SIZE 512 // Define the size of the sending buffer
#define RX_BUF_SIZE 128 // Define the size of the receiving buffer. 
#define RX_IDLE_BUF_SIZE 512 // Define the size of the idle receiving buffer (IDEL Mode)

/**
 * ! VARIABLES
 * 
 */
extern UART_HandleTypeDef huart1;// Declare the HAL library structure of USART1
extern DMA_HandleTypeDef hdma_usart1_rx; // Declare the HAL library structure of DMA for USART1
extern char RX_BUF[RX_BUF_SIZE]; // Define the receiving buffer
extern char RX_IDLE_BUF[RX_IDLE_BUF_SIZE];


/**
 * ! FUNCTION PROTOTYPES
 * 
 */

void MCU_serial_init(void);
void MCU_send(uint8_t *pData, uint16_t size); // lower level function wrapped by MCU_printf
void MCU_printf(const char *format, ...);

#ifndef IDLE_MODE
void HAL_UART_RxCpltCallback(UART_HandleTypeDef  *huart); 
#else
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t size);
#endif


#endif /* _BSP_USART_H_ */
