/**
 * @file bsp_init.c
 * @author SHUAIWEN CUI (SHUAIWEN001 AT e DOT ntu DOT edu DOT sg)
 * @brief
 * @version 1.0
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "bsp_init.h"

/**
 * @name VARIABLES
 * 
 */
// The gap between the initialization of each module, in ms.
int Init_Gap = 500;

/**
 * @name BSP_Init
 * @brief board support package initialization
 * @param None
 * @retval 0
 *
 */
int BSP_Init(void)
{
    // Variables
    int i;
#ifdef MODULE_ENABLE_LED
    // BSP Initialization - LED - flash once to indicate OK
    LED(0); // for deployment, switch off the LED to save power
#ifdef BSP_INIT_TEST // for debugging, flash the LED to indicate status
    LED(1);
    HAL_Delay(200);
    LED(0);
    HAL_Delay(200);
    LED(1);
#endif
#endif

#ifdef MODULE_ENABLE_KEY
    // BSP Initialization - Key
    // nothing required
#endif

    HAL_Delay(2*Init_Gap); // to give the user enough time to connect to the serial terminal

#ifdef MODULE_ENABLE_USART1
#ifdef BSP_INIT_TEST
    // Initialization - Count Down
    for (i = 0; i < 5; i++)
    {
        printf("[INITIALIZATION] Count Down for Upcoming Testing: %d \n\r", 5 - i);
        HAL_Delay(1000);
    }
    printf("\n\r");
#endif
    // BSP Initialization - Serial Communication
    MCU_serial_init();
    printf("[INITIALIZATION] Serial Communication - SUCCESS\n\r\n\r");
    // MCU_printf("Serial Communication - SUCCESS\n\r"); // not working
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_SDRAM
    // BSP Initialization - SDRAM
    printf("[INITIALIZATION] SDRAM Initialization - START\n\r");
    SDRAM_InitSequence();
    printf("[INITIALIZATION] SDRAM Initialization - FINISHED\r\n\n\r");
#ifdef BSP_INIT_TEST
    if (SDRAM_Test() == 0)
    {
        printf("[INITIALIZATION] SDRAM TEST - SUCCESS\r\n\n\r");
    }
    else
    {
        printf("[INITIALIZATION] SDRAM TEST - FAIL\r\n\n\r");
    }
#endif
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_MEMORY
    // BSP Initialization - Memory Management
    printf("[INITIALIZATION] Memory Management Initialization - START\n\r");
    memory_init();
    printf("[INITIALIZATION] Memory Management Initialization - FINISHED\n\r\n\r");
#ifdef BSP_INIT_TEST
    printf("[INITIALIZATION] Memory Management Test - START\n\r");
    if (memory_management_test() == 0)
    {
        printf("[INITIALIZATION] Memory Management Test - SUCCESS\n\r\n\r");
    }
    else
    {
        printf("[INITIALIZATION] Memory Management Test - FAIL\n\r\n\r");
    }
#endif
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_SDCARD

    // BSP Initialization - SD Card
    printf("[INITIALIZATION] SD Card Initialization - START.\n\r");
    SD_Init();
#ifdef BSP_INIT_TEST
    // SD Card Test
    printf("[INITIALIZATION] SD Card Test - START.\n\r");
    SD_Test();
    printf("[INITIALIZATION] SD Card Test - FINISHED.\n\r");
#endif
    printf("[INITIALIZATION] SD CARD Initialization - FINISHED.\n\r");
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_FILE // the test is kept outside the test zone, as sd card hard conenction is not quite stable, and we need the test to ensure the connection is okay

    printf("[INITIALIZATION] SD Card File IO Initialization and Test - START.\n\r");
    printf("\n\r");

    // mount the file system
    printf("[INITIALIZATION] Mounting the file system.\n\r");
    Mount_FatFs();
    printf("\n\r");

    // get disk information
    printf("[INITIALIZATION] Getting disk information.\n\r");
    FatFs_GetDiskInfo();
    printf("\n\r");

    // scan the directory
    printf("[INITIALIZATION] Scanning the directory.\n\r");
    FatFs_ScanDir("0:/");
    printf("\n\r");

    // write a text file
    printf("[INITIALIZATION] Writing a text file.\n\r");
    FatFs_WriteTXTFile("test.txt", 2016, 11, 15);
    printf("\n\r");

    // read a text file
    printf("[INITIALIZATION] Reading a text file.\n\r");
    FatFs_ReadTXTFile("test.txt");
    printf("\n\r");

    // get file information
    printf("[INITIALIZATION] Getting file information.\n\r");
    FatFs_GetFileInfo("test.txt");
    printf("\n\r");

    // delete a file
    printf("[INITIALIZATION] Deleting a file.\n\r");
    FatFs_DeleteFile("test.txt");
    printf("\n\r");

#ifdef BSP_INIT_TEST

#endif
    printf("[INITIALIZATION] SD Card File IO Initialization and Test - FINISHED.\n\r\n\r");
    HAL_Delay(Init_Gap);

#endif


#ifdef MODULE_ENABLE_USART1
    printf("[INITIALIZATION] BSP Initialization - FINISHED\n\r");
    printf("\n\r");
#endif

    return BSP_INIT_SUCCESS;
}

#ifdef MODULE_ENABLE_USART1

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