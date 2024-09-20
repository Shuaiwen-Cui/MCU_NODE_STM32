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

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_OLED
    // BSP Initialization - OLED
    printf("[NODE INITIALIZATION] OLED Initialization - START\n\r");

    OLED_Init();
    OLED_NewFrame();
    OLED_DrawImage((128 - (copilotImg.w)) / 2, 0, &copilotImg, OLED_COLOR_NORMAL);
    OLED_PrintString(32, 64 - 16, "LIFTNODE", &font16x16, OLED_COLOR_NORMAL);
    OLED_ShowFrame();

    printf("[NODE INITIALIZATION] OLED Initialization - FINISHED\n\r");
    printf("\n\r");
#endif

    HAL_Delay(10*Init_Gap);

#ifdef MODULE_ENABLE_MPU6050
    // BSP Initialization - MPU6050
    printf("[NODE INITIALIZATION] MPU6050 Initialization - START.\n\r");
    while (MPU6050_Init(&hi2c2) == 1)
        ;
    printf("[NODE INITIALIZATION] MPU6050 Initialization - DONE.\n\r\n\r");
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_ADXL355
    // BSP Initialization - ADXL355
    printf("[NODE INITIALIZATION] ADXL355 Initialization - START.\n\r");
    ADXL355_Init();
    printf("[NODE INITIALIZATION] ADXL355 Initialization - DONE.\n\r\n\r");
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
