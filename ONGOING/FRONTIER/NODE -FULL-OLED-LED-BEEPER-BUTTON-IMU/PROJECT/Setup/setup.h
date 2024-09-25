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

/*
 ========================================================================== INCLUDE - Necessary Libraries
 */
/* Necessary Libraries */
#include <stdio.h>
#include <math.h>

/*
 ========================================================================== INFORMATION
 */
/* NODE INFO */
extern char NodeName[];
extern int NodeID;

/* WIFI */
extern char WIFI_SSID[];
extern char WIFI_PASSWORD[];

/*
 ========================================================================== CONFIGURATIONS
 */

extern char *liftnode_folders[];

extern char *config_files[];

/* TRIGGERING MECHANISM*/
typedef struct
{
    // triggering parameters
    float activate_threshold_x;
    float activate_threshold_y;
    float activate_threshold_z;
    int activate_duration;
    float inactivate_threshold_x;
    float inactivate_threshold_y;
    float inactivate_threshold_z;
    int inactivate_duration;
    // triggering counters
    int cnt_activate;
    int cnt_inactivate;
    // triggering flags
    int activate_flag;
    int activate_led_flag;
} Triggering_Mechanism;

extern Triggering_Mechanism LiftNode_TM;

/* SENSING SETUP*/
extern int sensing_rate;
extern int sensing_duration;

/* FILE SYSTEM */
#define NUM_FOLDERS 2
#define NUM_CFG_FILES 3

/* CONFIGURATIONS IN SD CARD*/
extern int record_num; // the number of records in the SD card

/*
 ========================================================================== VARIABLES
 */
/* IMU */
typedef struct
{
    int Calibration_Rate;
    int Calibration_Duration;
    float Mean_AccX_G_Proj;
    float Mean_AccY_G_Proj;
    float Mean_AccZ_G_Proj;
    float Std_AccX_G_Proj;
    float Std_AccY_G_Proj;
    float Std_AccZ_G_Proj;
    float Acc_Scale;
} IMU_Calibration;

extern IMU_Calibration IMU_Calibration_Instance;

/* BUTTON */
extern int button_trigger;

/* DATA */
typedef struct{
    int sampling_rate;
    int sampling_duration;
    int sampling_points;
    float dt;
    float *ch01_data;
    float *ch02_data;
    float *ch03_data;
}Data_Structure;

extern Data_Structure LiftNode_Data;

/*
 ========================================================================== MACROS & MODULES - Corresponding to the 'INCLUDE' below
 */

/**
 * @name MACROS
 */
#define NODE_SUCCESS 0
#define NODE_FAIL 1

/**
 * @name MAIN CONTROL MODULE CONFIGURATION
 * @brief This section is to determine the modules to be included in the project
 * ! This is where you configure the modules to be included in the project
 * @param MODULE_ENABLE_LED //! Enable LED module
 * @param MODULE_ENABLE_USART //! Enable USART
 * @param MODULE_ENABLE_SDRAM //! Enable SDRAM module to use external RAM for computation
 * @param MODULE_ENABLE_MEMORY //! Enable Memory module - for memory management on SDRAM
 * @param MODULE_ENABLE_SDCARD //! Enable SD Card module- for SD Card basic io. !!! This module can not be used together with MODULE_ENABLE_FILE. Better to disable this and use the MODULE_ENABLE_FILE. Enabling FATFS in CubeMX may lead to fail of this option, and you may need to reformat the SD card before using next time.
 * @param MODULE_ENABLE_FILE //! Enable File module - for file operations on SD Card !!! This module can not be used together with MODULE_ENABLE_SDCARD. Better to enable this.
 */
#define MODULE_ENABLE_LED    // Enable LED module
#define MODULE_ENABLE_USART  // Enable USART module
#define MODULE_ENABLE_SDRAM  // Enable SDRAM module
#define MODULE_ENABLE_MEMORY // Enable Memory module - for memory management on SDRAM
// #define MODULE_ENABLE_SDCARD // Enable SD Card module
#define MODULE_ENABLE_FILE // Enable File module - for file operations on SD Card

/**
 * @name PERIPHERAL COMPONENT CONFIGURATION
 * @brief This section is to determine the peripheral components to be incorporated in the project
 * ! This is where you configure the peripheral components to be included in the projec
 * @param MODULE_ENABLE_OLED //! Enable OLED module
 * @param MODULE_ENABLE_RGB //! Enable RGB LED module
 * @param MODULE_ENABLE_BUZZER //! Enable Buzzer module
 * @param MODULE_ENABLE_BUTTON //! Enable Button module
 * @param MODULE_ENABL_MPU6050 //! Enable IMU MPU6050 module
 *
 */
#define MODULE_ENABLE_OLED    // Enable OLED module
#define MODULE_ENABLE_RGB     // Enable RGB LED module
#define MODULE_ENABLE_BUZZER  // Enable Buzzer module
#define MODULE_ENABLE_BUTTON  // Enable Button module
#define MODULE_ENABLE_MPU6050 // Enable IMU MPU6050 module

/**
 * @name CMSIS COMPUTATION
 * @brief This section is to determine the configuration about CMSIS computation
 * ! This is where you configure the CMSIS computation libraries to be included in the project
 * @param MODULE_ENABLE_CMSIS_DSP //! Enable CMSIS DSP library
 * @param MODULE_ENABLE_CMSIS_NN //! Enable CMSIS NN library
 */
#define MODULE_ENABLE_CMSIS_DSP
#define MODULE_ENABLE_CMSIS_NN

/**
 * @name TinySHM COMPONENT CONFIGURATION
 * @brief This section is to determine the TinySHM components to be incorporated in the project
 * ! This is where you configure the TinySHM components to be included in the project
 * @param MODULE_ENABLE_TINYSHM_SENSING //! Enable TinySHM Sensing module
 * @param MODULE_ENABLE_TINYSHM_FILESYSTEM //! Enable TinySHM File System module
 */
#define MODULE_ENABLE_TINYSHM_SENSING    // Enable TinySHM Sensing module
#define MODULE_ENABLE_TINYSHM_FILESYSTEM // Enable TinySHM File System module

/*
 ========================================================================== INCLUDE - According to the MODULE configuration above
 */



/* Main Control BSP */
// LED for Status Indication
#ifdef MODULE_ENABLE_LED
#include "bsp_led.h"
#endif

// USART for Debugging & Communication
#ifdef MODULE_ENABLE_USART //! Note - Do rember to check the MicroLib option in the project settings
#include "bsp_usart.h"
#endif

// SDRAM for Computation
#ifdef MODULE_ENABLE_SDRAM
#include "bsp_sdram.h"
#endif

// Memory Management
#ifdef MODULE_ENABLE_MEMORY
#include "bsp_memory.h"
#endif

// SD Card for Large Volume Storage
#ifdef MODULE_ENABLE_SDCARD
#include "bsp_sdcard.h"
#endif

// File System Wrap-up
#ifdef MODULE_ENABLE_FILE
#include "bsp_file.h"
#endif

/* Peripheral Components */
// OLED for Interfacing
#ifdef MODULE_ENABLE_OLED
#include "font.h"
#include "oled.h"
#endif

// RGB LED for Status Indication
#ifdef MODULE_ENABLE_RGB
#include "led_rgb.h"
#endif

// Buzzer for Sound Indication
#ifdef MODULE_ENABLE_BUZZER
#include "buzzer.h"
#endif

// Button for Interaction
#ifdef MODULE_ENABLE_BUTTON
#include "button.h"
#endif

// MPU6050 for IMU
#ifdef MODULE_ENABLE_MPU6050
#include "mpu6050.h"
#endif

/* CMSIS Libs */
// CMSIS DSP
#ifdef MODULE_ENABLE_CMSIS_DSP
#include "arm_math.h"
#include "arm_const_structs.h"
#include "arm_common_tables.h"
#endif

// CMSIS NN
#ifdef MODULE_ENABLE_CMSIS_NN
#include "arm_nnfunctions.h"
#include "arm_nn_tables.h"
#include "arm_nnsupportfunctions.h"
#endif

/* TinySHM Components */

// TinySHM Sensing
#ifdef MODULE_ENABLE_TINYSHM_SENSING
#include "Sensing.h"
#endif

// TinySHM File System
#ifdef MODULE_ENABLE_TINYSHM_FILESYSTEM
#include "FileSystem.h"
#endif

/*
 ========================================================================== FILE SYSTEM RELATED VARIABLES
 */

/* FILE SYSTEM */
// FATFS SDFatFS;    // already defined in fatfs.c
// FIL SDFile;       // already defined in fatfs.c
extern FRESULT fr;      // FatFs function common result code
extern FILINFO finfo;     // File information
extern UINT bw;         // File write count

/*
 ========================================================================== FUNCTION PROTOTYPING
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