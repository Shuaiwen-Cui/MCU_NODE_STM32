/**
 * @file bsp_usart.c
 * @author SHUAIWEN CUI (shuaiwencui@gmail.com)
 * @brief This is the source file for the bsp_usart.c file
 * @version 1.0
 * @date 2024-06-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "bsp_usart.h"

/**
 * @name test part
 *
 */

char RX_BUF[RX_BUF_SIZE];           // Define the receiving buffer
char RX_IDLE_BUF[RX_IDLE_BUF_SIZE]; // Define the idle receiving buffer (IDEL Mode)

/**
 * @name MCU_serial_init
 * @brief This function is used to initialize the USART1, and the reception method is according to the reception mode RX_MODE defined in the bsp_usart.h file. The normal mode is the blocking mode, not recommended as it will block the main loop and causes waste of CPU resources; the interrupt mode is recommended; and the DMA mode is the most recommended.
 *
 */
void MCU_serial_init(void)
{
    // Note the last element in the buffer can be "\n", as every time you send message from PC, a "\n" is appended to the end of your message.

    if (RX_MODE == 0)
    {
        HAL_UART_Receive(&huart1, (uint8_t *)&RX_BUF, RX_BUF_SIZE, HAL_MAX_DELAY); // Initial receive
        // memset(RX_BUF, 0, sizeof(RX_BUF));
    }
    else if (RX_MODE == 1)
    {
        HAL_UART_Receive_IT(&huart1, (uint8_t *)&RX_BUF, RX_BUF_SIZE); // Enable receive interrupt
        // memset(RX_BUF, 0, sizeof(RX_BUF));
    }
    else if (RX_MODE == 2)
    {
        HAL_UART_Receive_DMA(&huart1, (uint8_t *)&RX_BUF, RX_BUF_SIZE); // Enable receive interrupt
        // memset(RX_BUF, 0, sizeof(RX_BUF));
    }
    else if (RX_MODE == 3)
    {
        // Enable the idle mode DMA reception
        HAL_UARTEx_ReceiveToIdle_DMA(&huart1, (uint8_t *)&RX_IDLE_BUF, sizeof(RX_IDLE_BUF)); // Enable receive interrupt
        // memset(RX_IDLE_BUF, 0, sizeof(RX_IDLE_BUF));
        // __HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT); // Disable the half-transfer interrupt
    }
}

/**
 * @name MCU_Send
 * @brief This function is used to send data through the USART1, and the transmission method is according to the transmission mode TX_MODE defined in the bsp_usart.h file
 * @param pData: The pointer to the data to be sent
 * @param size: The size of the data to be sent
 * @retval None
 *
 */
void MCU_send(uint8_t *pData, uint16_t size)
{
    if (TX_MODE == 0) // blocking mode - not recommended
    {
        HAL_UART_Transmit(&huart1, pData, size, HAL_MAX_DELAY);
    }
    else if (TX_MODE == 1) // interrupt mode - recommended
    {
        HAL_UART_Transmit_IT(&huart1, pData, size);
    }
    else if (TX_MODE == 2) // DMA mode - recommended
    {
        HAL_UART_Transmit_DMA(&huart1, pData, size);
    }
}

/**
 * @name MCU_printf
 * @brief This function is used to send formatted data through the USART1, and the transmission method is according to the transmission mode TX_MODE defined in the bsp_usart.h file
 * @param format: The pointer to the formatted string to be sent
 * @param ...: The arguments to be formatted
 * @retval None
 *
 */
void MCU_printf(const char *format, ...)
{
    char TX_BUF[TX_BUF_SIZE]; // Define the sending buffer
    va_list args;
    va_start(args, format);
    vsnprintf(TX_BUF, TX_BUF_SIZE, format, args);
    va_end(args);
    MCU_send((uint8_t *)TX_BUF, strlen(TX_BUF));
}

#ifndef IDLE_MODE
/**
 * @name HAL_UART_RxCpltCallback
 * @brief This function is the callback function for the USART1 receive interrupt, and the received data is stored in the RX_BUF array
 *
 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) // Serial port interrupt callback function
{
    if (huart == &huart1) // Determine the source of the interrupt (serial port 1: USB to serial port)
    {
        if (RX_MODE == 1)
        {
            MCU_send((uint8_t *)RX_BUF, strlen(RX_BUF));
            HAL_UART_Receive_IT(&huart1, (uint8_t *)&RX_BUF, RX_BUF_SIZE); // Enable receive interrupt
        }
        else if (RX_MODE == 2)
        {
            MCU_send((uint8_t *)RX_BUF, strlen(RX_BUF));
            HAL_UART_Receive_DMA(&huart1, (uint8_t *)&RX_BUF, RX_BUF_SIZE); // Enable receive interrupt
        }
    }
}

#else

/**
 * @name HAL_UARTEx_RxEventCallback
 * @brief This function is the callback function for the USART1 receive idle interrupt, and the received data is stored in the RX_BUF array
 * ! Note: this function has higher priority than HAL_UART_RxCpltCallback, if this function is defined, HAL_UART_RxCpltCallback will not be called
 *
 */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t size)
{
    if (huart == &huart1) // Determine the source of the interrupt (serial port 1: USB to serial port)
    {
        if (RX_MODE == 3)
        {
            MCU_send((uint8_t *)RX_IDLE_BUF, size);                                              //! the size here is provided by the passed parameter size
            HAL_UARTEx_ReceiveToIdle_DMA(&huart1, (uint8_t *)&RX_IDLE_BUF, sizeof(RX_IDLE_BUF)); // Enable receive interrupt
            // __HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT);                                    // Disable the half-transfer interrupt
            //    memset(RX_IDLE_BUF, 0, sizeof(RX_IDLE_BUF));
        }
    }
}
#endif
