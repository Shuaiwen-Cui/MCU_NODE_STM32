# SETUP

!!! Note
    'SETUP' refers to node configuration and initialization. This step means to configure the basic information, functional modules of the hardware, controlling the BSP, Peripheral, and other systems. 

## HOW TO SETUP

There is a standalone folder named 'Setup' in both the file structure and the project structure. To modify the configuration for node initialization, you just need to modify the parameters and macros in either the .h or the .c file.

## SETUP SCOPE

'Setup' covers almost all important configurable information, modules, macros, and variables.

## CODE

### setup.h

```c
/**
 * @file setup.h
 * @author SHUAIWEN CUI (SHUAIWEN001 AT e DOT ntu DOT edu DOT sg)
 * @brief This file is for MCU node configuration and initialization setup.
 * @version 1.0
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _SETUP_H_
#define _SETUP_H_

/**
 * @name MACROS
 */
#define NODE_SUCCESS 0
#define NODE_FAIL 1

/**
 * @name CONFIGURATION
 * @brief This section is to determine the modules to be included in the project
 * ! This is where you configure the modules to be included in the project
 * @param MODULE_ENABLE_LED //! Enable LED module
 * @param MODULE_ENABLE_USART //! Enable USART
 * @param MODULE_ENABLE_SDRAM //! Enable SDRAM module to use external RAM for computation
 * @param MODULE_ENABLE_MEMORY //! Enable Memory module - for memory management on SDRAM
 * @param MODULE_ENABLE_SDCARD //! Enable SD Card module- for SD Card basic io. !!! This module can not be used together with MODULE_ENABLE_FILE. Better to disable this and use the MODULE_ENABLE_FILE. Enabling FATFS in CubeMX may lead to fail of this option, and you may need to reformat the SD card before using next time.
 * @param MODULE_ENABLE_FILE //! Enable File module - for file operations on SD Card !!! This module can not be used together with MODULE_ENABLE_SDCARD. Better to enable this.
 */
#define MODULE_ENABLE_LED // Enable LED module
#define MODULE_ENABLE_USART // Enable USART module
#define MODULE_ENABLE_SDRAM  // Enable SDRAM module
#define MODULE_ENABLE_MEMORY // Enable Memory module - for memory management on SDRAM
// #define MODULE_ENABLE_SDCARD // Enable SD Card module
#define MODULE_ENABLE_FILE   // Enable File module - for file operations on SD Card

// Necessary Libraries
#include <stdio.h>

// LED for Status Indication
#ifdef MODULE_ENABLE_LED
#include "bsp_led.h"
#endif

#ifdef MODULE_ENABLE_USART //! Note - Do rember to check the MicroLib option in the project settings
#include "bsp_usart.h"
#endif

#ifdef MODULE_ENABLE_SDRAM
#include "bsp_sdram.h"
#endif

#ifdef MODULE_ENABLE_MEMORY
#include "bsp_memory.h"
#endif

#ifdef MODULE_ENABLE_SDCARD
#include "bsp_sdcard.h"
#endif

#ifdef MODULE_ENABLE_FILE
#include "bsp_file.h"
#endif

/**
 * @name NODE INFORMATION
 */

/**
 * @name FUNCTION PROTOTYPING
 */

/**
 * @name Node_Init
 * @brief This function is for board initialization, with configurable initialization test incorporated.
 */
int Node_Init(void);

#ifdef MODULE_ENABLE_USART
// IO retargetting
int fputc(int ch, FILE *f);
int fgetc(FILE *f);
#endif

#endif /* _SETUP_H_ */
```

### setup.c

```c
/**
 * @file setup.c
 * @author SHUAIWEN CUI (SHUAIWEN001 AT e DOT ntu DOT edu DOT sg)
 * @brief This file is for MCU node configuration and initialization setup.
 * @version 1.0
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "setup.h"

/**
 * @name INITIALIZATION TEST
 * @brief This determines whether to conduct test when initializing the node. To disenable, comment it out.
 */
int init_test_mode = 0; // 0 for not, 1 for yes.

/**
 * @name VARIABLES
 *
 */
// The gap between the initialization of each module, in ms.
int Init_Gap = 300;

/**
 * @name Node_Init
 * @brief This function is for board initialization, with configurable initialization test incorporated.
 */
int Node_Init(void)
{
    // Variables
    int i;

    // COMPONNET-LED
#ifdef MODULE_ENABLE_LED
    LED(0);                  // for deployment, switch off the LED to save power
    if (init_test_mode == 1) // for debugging, flash the LED to indicate status
    {
        LED(1);
        HAL_Delay(200);
        LED(0);
        HAL_Delay(200);
        LED(1);
    }
#endif

    // COMPONENT-USART-SERIAL Communication
#ifdef MODULE_ENABLE_USART
    if (init_test_mode == 1)
    {
        for (i = 0; i < 3; i++)
        {
            printf("[NODE INITIALIZATION] Count Down for Upcoming Testing: %d \n\r", 3 - i);
            HAL_Delay(1000);
        }
        printf("\n\r");
    }
    printf("[NODE INITIALIZATION] Serial Communication - SUCCESS.\n\r\n\r");
#endif

    HAL_Delay(Init_Gap); // to give the user enough time to connect to the serial terminal

    // COMPONENT-SDRAM
#ifdef MODULE_ENABLE_SDRAM
    // BSP Initialization - SDRAM
    printf("[NODE INITIALIZATION] SDRAM Initialization - START.\n\r");
    SDRAM_InitSequence();
    printf("[NODE INITIALIZATION] SDRAM Initialization - DONE.\n\r\n\r");
    if (init_test_mode == 1)
    {
        if (SDRAM_Test() == 0)
        {
            printf("[NODE INITIALIZATION] SDRAM TEST - SUCCESS.\n\r\n\r");
        }
        else
        {
            printf("[NODE INITIALIZATION] SDRAM TEST - FAIL.\n\r\n\r");
        }
    }
#endif

    HAL_Delay(Init_Gap);

    // COMPONENT-MEMORY MANAGEMENT - SDRAM
#ifdef MODULE_ENABLE_MEMORY
    printf("[NODE INITIALIZATION] Memory Management Initialization - START.\n\r");
    memory_init();
    printf("[NODE INITIALIZATION] Memory Management Initialization - DONE.\n\r\n\r");
    if (init_test_mode == 1)
    {
        printf("[NODE INITIALIZATION] Memory Management Test - START.\n\r");
        if (memory_management_test() == 0)
        {
            printf("[NODE INITIALIZATION] Memory Management Test - SUCCESS.\n\r\n\r");
        }
        else
        {
            printf("[NODE INITIALIZATION] Memory Management Test - FAIL.\n\r\n\r");
        }
    }
#endif

    HAL_Delay(Init_Gap);

    // COMPONENT-SDCARD (If you use FATFS, don't enable this.)
#ifdef MODULE_ENABLE_SDCARD
    printf("[NODE INITIALIZATION] SD Card Initialization - START.\n\r");
    SD_Init();
    printf("[NODE INITIALIZATION] SD CARD Initialization - DONE.\n\r");
    if (init_test_mode == 1)
    {
        // SD Card Test
        printf("[NODE INITIALIZATION] SD Card Test - START.\n\r");
        SD_Test();
        printf("[NODE INITIALIZATION] SD Card Test - DONE.\n\r");
    }
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_FILE // the test is kept outside the test zone, as sd card hard conenction is not quite stable, and we need the test to ensure the connection is okay

    printf("[NODE INITIALIZATION] SD Card File IO Initialization and Test - START.\n\r");
    printf("\n\r");

    // mount the file system
    printf("[NODE INITIALIZATION] Mounting the file system.\n\r");
    Mount_FatFs();
    printf("\n\r");

    // get disk information
    printf("[NODE INITIALIZATION] Getting disk information.\n\r");
    FatFs_GetDiskInfo();
    printf("\n\r");

    if (init_test_mode == 1)
    {
        // scan the directory
        printf("[NODE INITIALIZATION] Scanning the directory.\n\r");
        FatFs_ScanDir("0:/");
        printf("\n\r");

        // write a text file
        printf("[NODE INITIALIZATION] Writing a text file.\n\r");
        FatFs_WriteTXTFile("test.txt", 2016, 11, 15);
        printf("\n\r");

        // read a text file
        printf("[NODE INITIALIZATION] Reading a text file.\n\r");
        FatFs_ReadTXTFile("test.txt");
        printf("\n\r");

        // get file information
        printf("[NODE INITIALIZATION] Getting file information.\n\r");
        FatFs_GetFileInfo("test.txt");
        printf("\n\r");

        // delete a file
        printf("[NODE INITIALIZATION] Deleting a file.\n\r");
        FatFs_DeleteFile("test.txt");
        printf("\n\r");
    }
    printf("[NODE INITIALIZATION] SD Card FATFS File IO Initialization - DONE.\n\r\n\r");
#endif

    return NODE_SUCCESS;
}

#ifdef MODULE_ENABLE_USART
// MicroLib needed for retargetting
// retarget fputc for printf
int fputc(int ch, FILE *f)
{
    uint8_t temp = (uint8_t)ch;
    HAL_UART_Transmit(&huart1, &temp, 1, HAL_MAX_DELAY);
    return ch;
}

// retarget fgetc for scanf
int fgetc(FILE *f)
{
    while (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE) == RESET)
        ;                                      // Wait until the data is received
    return (int)(huart1.Instance->RDR & 0xFF); // Read the received data
}
#endif
```