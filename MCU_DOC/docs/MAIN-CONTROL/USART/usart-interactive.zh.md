# 通用同步/异步收发器（USART）

USART可以用于多种不同的用途，目前我们只使用USART1进行串行通信。

!!! alert
    此版本用于交互式版本，USART1 的中断和DMA功能没有启用。因此，串口信息的输入和输出都是通过阻塞模式进行的。如果需要使用中断和DMA功能，请参阅“非交互式”版本。

## USART1电路
![USART1_CIRCUIT](usart_circuit.png)

从电路设计可以看出，USART1的RX和TX分别是PA9和PA10。然而，默认选择的引脚并不是这两个，因此我们需要在屏幕右侧的引脚配置中手动更改它们。

## USART1配置

### 参数设置
![PARAMETER](config_usart_para.png)

选择“参数设置”以设置USART1的参数。我们暂时保持默认设置。

## 生成与更新代码
接下来，我们生成代码以保存当前进度，并使其准备好进行后续的编程步骤。点击屏幕右上角的“生成代码”按钮。

## 在Keil中编程

### 整合模块代码

我们已经介绍了如何将BSP代码移植并整合到项目中，这适用于每个相应的模块。对于移植：

1. 从BSP项目中复制模块代码到用户项目中。
2. 将模块代码添加到用户项目的包含路径中。
3. 将模块代码添加到项目项中。
4. 在用户项目中包含模块代码的头文件。
5. 在用户项目中调用模块函数。

!!! tip
    请记得在魔棒工具中，在目标选项下，代码生成区域中，勾选使用MicroLIB。这个库使得我们可以使用printf函数。

### 代码审查 - USART

让我们审查USART模块的代码。

#### **iusart.h**

```c
/**
 * @file iusart.h
 * @author SHUAIWEN CUI (shuaiwencui AT gmail DOT com)
 * @brief This is the header file for the iusart.c file
 * @version 1.0
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef IUSART_H_
#define IUSART_H_

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


// #define TX_MODE 2 // Define the transmission mode: 0 - blocking mode (not recommended), 1 - interrupt mode (* recommended), and 2 - DMA mode (** recommended) !!! note that mode 2 sometimes does not work, not sure about the reason.
// #define RX_MODE 3 // Define the reception mode: 0 - blocking mode (not recommended), 1 - interrupt mode (recommended), and 2 - DMA mode (recommended); 3 - DMA IDLE mode (recommended) (only when IDLE_MODE is enabled)

// //IDLE mode means non fixed length of data, the data is received until the idle line is detected
// #if RX_MODE >= 3
// #define IDLE_MODE 
// #endif

// #define TX_BUF_SIZE 512 // Define the size of the sending buffer
// #define RX_BUF_SIZE 128 // Define the size of the receiving buffer. 
// #define RX_IDLE_BUF_SIZE 512 // Define the size of the idle receiving buffer (IDEL Mode)

/**
 * ! VARIABLES
 * 
 */
extern UART_HandleTypeDef huart1;// Declare the HAL library structure of USART1
extern DMA_HandleTypeDef hdma_usart1_rx; // Declare the HAL library structure of DMA for USART1
// extern char RX_BUF[RX_BUF_SIZE]; // Define the receiving buffer
// extern char RX_IDLE_BUF[RX_IDLE_BUF_SIZE];


/**
 * ! FUNCTION PROTOTYPES
 * 
 */

// void MCU_serial_init(void);
// void MCU_send(uint8_t *pData, uint16_t size); // lower level function wrapped by MCU_printf
// void MCU_printf(const char *format, ...);

// #ifndef IDLE_MODE
// void HAL_UART_RxCpltCallback(UART_HandleTypeDef  *huart); 
// #else
// void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t size);
// #endif


#endif /* IUSART_H_ */


```

#### **iusart.c**

```c
/**
 * @file iusart.c
 * @author SHUAIWEN CUI (shuaiwencui@gmail.com)
 * @brief This is the source file for the iusart.c file
 * @version 1.0
 * @date 2024-06-24
 *
 * @copyright Copyright (c) 2024
 *
 */

// #include "iusart.h"

// /**
//  * @name test part
//  *
//  */

// char RX_BUF[RX_BUF_SIZE];           // Define the receiving buffer
// char RX_IDLE_BUF[RX_IDLE_BUF_SIZE]; // Define the idle receiving buffer (IDEL Mode)

// /**
//  * @name MCU_serial_init
//  * @brief This function is used to initialize the USART1, and the reception method is according to the reception mode RX_MODE defined in the iusart.h file. The normal mode is the blocking mode, not recommended as it will block the main loop and causes waste of CPU resources; the interrupt mode is recommended; and the DMA mode is the most recommended.
//  *
//  */
// void MCU_serial_init(void)
// {
//     // Note the last element in the buffer can be "\n", as every time you send message from PC, a "\n" is appended to the end of your message.

//     if (RX_MODE == 0)
//     {
//         HAL_UART_Receive(&huart1, (uint8_t *)&RX_BUF, RX_BUF_SIZE, HAL_MAX_DELAY); // Initial receive
//         // memset(RX_BUF, 0, sizeof(RX_BUF));
//     }
//     else if (RX_MODE == 1)
//     {
//         HAL_UART_Receive_IT(&huart1, (uint8_t *)&RX_BUF, RX_BUF_SIZE); // Enable receive interrupt
//         // memset(RX_BUF, 0, sizeof(RX_BUF));
//     }
//     else if (RX_MODE == 2)
//     {
//         HAL_UART_Receive_DMA(&huart1, (uint8_t *)&RX_BUF, RX_BUF_SIZE); // Enable receive interrupt
//         // memset(RX_BUF, 0, sizeof(RX_BUF));
//     }
//     else if (RX_MODE == 3)
//     {
//         // Enable the idle mode DMA reception
//         HAL_UARTEx_ReceiveToIdle_DMA(&huart1, (uint8_t *)&RX_IDLE_BUF, sizeof(RX_IDLE_BUF)); // Enable receive interrupt
//         // memset(RX_IDLE_BUF, 0, sizeof(RX_IDLE_BUF));
//         // __HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT); // Disable the half-transfer interrupt
//     }
// }

// /**
//  * @name MCU_Send
//  * @brief This function is used to send data through the USART1, and the transmission method is according to the transmission mode TX_MODE defined in the iusart.h file
//  * @param pData: The pointer to the data to be sent
//  * @param size: The size of the data to be sent
//  * @retval None
//  *
//  */
// void MCU_send(uint8_t *pData, uint16_t size)
// {
//     if (TX_MODE == 0) // blocking mode - not recommended
//     {
//         HAL_UART_Transmit(&huart1, pData, size, HAL_MAX_DELAY);
//     }
//     else if (TX_MODE == 1) // interrupt mode - recommended
//     {
//         HAL_UART_Transmit_IT(&huart1, pData, size);
//     }
//     else if (TX_MODE == 2) // DMA mode - recommended
//     {
//         HAL_UART_Transmit_DMA(&huart1, pData, size);
//     }
// }

// /**
//  * @name MCU_printf
//  * @brief This function is used to send formatted data through the USART1, and the transmission method is according to the transmission mode TX_MODE defined in the iusart.h file
//  * @param format: The pointer to the formatted string to be sent
//  * @param ...: The arguments to be formatted
//  * @retval None
//  *
//  */
// void MCU_printf(const char *format, ...)
// {
//     char TX_BUF[TX_BUF_SIZE]; // Define the sending buffer
//     va_list args;
//     va_start(args, format);
//     vsnprintf(TX_BUF, TX_BUF_SIZE, format, args);
//     va_end(args);
//     MCU_send((uint8_t *)TX_BUF, strlen(TX_BUF));
// }

// #ifndef IDLE_MODE
// /**
//  * @name HAL_UART_RxCpltCallback
//  * @brief This function is the callback function for the USART1 receive interrupt, and the received data is stored in the RX_BUF array
//  *
//  */

// void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) // Serial port interrupt callback function
// {
//     if (huart == &huart1) // Determine the source of the interrupt (serial port 1: USB to serial port)
//     {
//         if (RX_MODE == 1)
//         {
//             MCU_send((uint8_t *)RX_BUF, strlen(RX_BUF));
//             HAL_UART_Receive_IT(&huart1, (uint8_t *)&RX_BUF, RX_BUF_SIZE); // Enable receive interrupt
//         }
//         else if (RX_MODE == 2)
//         {
//             MCU_send((uint8_t *)RX_BUF, strlen(RX_BUF));
//             HAL_UART_Receive_DMA(&huart1, (uint8_t *)&RX_BUF, RX_BUF_SIZE); // Enable receive interrupt
//         }
//     }
// }

// #else

// /**
//  * @name HAL_UARTEx_RxEventCallback
//  * @brief This function is the callback function for the USART1 receive idle interrupt, and the received data is stored in the RX_BUF array
//  * ! Note: this function has higher priority than HAL_UART_RxCpltCallback, if this function is defined, HAL_UART_RxCpltCallback will not be called
//  *
//  */
// void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t size)
// {
//     if (huart == &huart1) // Determine the source of the interrupt (serial port 1: USB to serial port)
//     {
//         if (RX_MODE == 3)
//         {
//             MCU_send((uint8_t *)RX_IDLE_BUF, size);                                              //! the size here is provided by the passed parameter size
//             HAL_UARTEx_ReceiveToIdle_DMA(&huart1, (uint8_t *)&RX_IDLE_BUF, sizeof(RX_IDLE_BUF)); // Enable receive interrupt
//             // __HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT);                                    // Disable the half-transfer interrupt
//             //    memset(RX_IDLE_BUF, 0, sizeof(RX_IDLE_BUF));
//         }
//     }
// }
// #endif

```
