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

/*
 ========================================================================== INFORMATION
 */
/* NODE INFO */
char NodeName[] = "LiftNode";
int NodeID = 1;

/* WIFI */
char WIFI_SSID[] = "CSW@CEE";
char WIFI_PASSWORD[] = "88888888";

/*
 ========================================================================== CONFIGURATIONS
 */
/* INITIALIZATION FUNCTION*/
int init_test_mode = 0; // 0 for not, 1 for yes.
int Init_Gap = 50;     // The gap between the initialization of each module, in ms.

/* FILE SYSTEM */
// FATFS SDFatFS;    // already defined in fatfs.c
// FIL SDFile;       // already defined in fatfs.c
FRESULT fr;      // FatFs function common result code
FILINFO finfo;     // File information
UINT bw;         // File write count

char *liftnode_folders[NUM_FOLDERS] = {
    "CONFIG",
    "DATA"};

char *config_files[NUM_CFG_FILES] = {
    "NODE_INFO.cfg",
    "INTERNET.cfg",
    "RECORD_NUM.cfg"
    };

/* TRIGGERING MECHANISM*/
Triggering_Mechanism LiftNode_TM = {
    // triggering parameters
    .activate_threshold_x = 0,
    .activate_threshold_y = 0,
    .activate_threshold_z = 0.03,
    .activate_duration = 1,
    .inactivate_threshold_x = 0,
    .inactivate_threshold_y = 0,
    .inactivate_threshold_z = 0.005,
    .inactivate_duration = 2,
    // triggering counters
    .cnt_activate = 0,
    .cnt_inactivate = 0,
    // triggering flags
    .activate_flag = 0,
    .activate_led_flag = 0};

/* SENSING SETUP*/
int sensing_rate = 100;
int sensing_duration = 60;

/* CONFIGURATIONS IN SD CARD*/
int record_num; // the number of records in the SD card

/*
 ========================================================================== VARIABLES
 */
/* IMU */
IMU_Calibration IMU_Calibration_Instance = {
    .Calibration_Rate = 100,   // Hz
    .Calibration_Duration = 5, // seconds
    .Mean_AccX_G_Proj = 0.0f,
    .Mean_AccY_G_Proj = 0.0f,
    .Mean_AccZ_G_Proj = 0.0f,
    .Std_AccX_G_Proj = 0.0f,
    .Std_AccY_G_Proj = 0.0f,
    .Std_AccZ_G_Proj = 0.0f,
    .Acc_Scale = 1.0f // can be modified as the sensing procedure goes on
};

/* DATA*/
Data_Structure LiftNode_Data = {
    .sampling_rate = 0,
    .sampling_duration = 0,
    .sampling_points = 0,
    .dt = 0,
    .ch01_data = NULL,
    .ch02_data = NULL,
    .ch03_data = NULL};

/* USER_INPUT*/
int button_trigger = 0; // mostly used in button interrupt handling

/*
 ========================================================================== FUNCTIONS
 */

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
    printf("[NODE INITIALIZATION] SD CARD Initialization - DONE.\n\r\n\r");
    if (init_test_mode == 1)
    {
        // SD Card Test
        printf("[NODE INITIALIZATION] SD Card Test - START.\n\r");
        SD_Test();
        printf("[NODE INITIALIZATION] SD Card Test - DONE.\n\r\n\r");
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

    printf("[NODE INITIALIZATION] OLED Initialization - FINISHED\n\r\n\r");
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_RGB
    // BSP Initialization - RGB LED
    printf("[NODE INITIALIZATION] RGB LED Initialization - START.\n\r");
    if (init_test_mode == 1)
    {
        LED_RGB(1, 0, 0);
        HAL_Delay(3 * Init_Gap);
        LED_RGB(0, 1, 0);
        HAL_Delay(3 * Init_Gap);
        LED_RGB(0, 0, 1);
        HAL_Delay(3 * Init_Gap);
        LED_RGB(1, 1, 1);
        HAL_Delay(3 * Init_Gap);
        LED_RGB(0, 0, 0);
        HAL_Delay(3 * Init_Gap);
    }
    else
    {
        LED_RGB(0, 1, 0);
        HAL_Delay(5 * Init_Gap);
        LED_RGB(0, 0, 0);
    }
    printf("[NODE INITIALIZATION] RGB LED Initialization - DONE.\n\r\n\r");
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_BUZZER
    // BSP Initialization - Buzzer
    printf("[NODE INITIALIZATION] Buzzer Initialization - START.\n\r");
    Buzzer_Beep(100);
    printf("[NODE INITIALIZATION] Buzzer Initialization - DONE.\n\r\n\r");
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_BUTTON
    // BSP Initialization - Button
    printf("[NODE INITIALIZATION] Button Initialization - START.\n\r");
    // nothing requried
    printf("[NODE INITIALIZATION] Button Initialization - DONE.\n\r\n\r");
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_MPU6050
    // BSP Initialization - MPU6050
    printf("[NODE INITIALIZATION] MPU6050 Initialization - START.\n\r");
    while (MPU6050_Init(&hi2c2) == 1)
        ;
    printf("[NODE INITIALIZATION] MPU6050 Initialization - DONE.\n\r\n\r");
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_TINYSHM_SENSING
    // Initialization - TinySHM Sensing
    printf("[NODE INITIALIZATION] Sensing Initialization - START.\n\r");
    MPU6050_Gravity_Projection(&IMU_Calibration_Instance);
    printf("[NODE INITIALIZATION] Sensing Initialization - DONE.\n\r\n\r");
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_TINYSHM_FILESYSTEM
    // Initialization - TinySHM File System
    printf("[NODE INITIALIZATION] File System Initialization - START.\n\r");
    Node_FS_Init();
    printf("[NODE INITIALIZATION] File System Initialization - DONE.\n\r\n\r");
#endif    

    // show ready
    printf("[NODE INITIALIZATION] Node Ready!\n\r\n\r");
#ifdef MODULE_ENABLE_RGB
    LED_RGB(0, 1, 0);
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
