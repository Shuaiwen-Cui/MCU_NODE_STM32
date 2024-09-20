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
#define MODULE_ENABLE_LED // Enable LED module
#define MODULE_ENABLE_USART // Enable USART module
#define MODULE_ENABLE_SDRAM  // Enable SDRAM module
#define MODULE_ENABLE_MEMORY // Enable Memory module - for memory management on SDRAM
// #define MODULE_ENABLE_SDCARD // Enable SD Card module
#define MODULE_ENABLE_FILE   // Enable File module - for file operations on SD Card

/**
 * @name PERIPHERAL COMPONENT CONFIGURATION
 * @brief This section is to determine the peripheral components to be incorporated in the project
 * ! This is where you configure the peripheral components to be included in the project
 * @param MODULE_ENABLE_OLED //! Enable OLED module
 * @param MODULE_ENABLE_MPU6050 //! Enable IMU MPU6050 module
 * @param MODULE_ENABLE_ADXL355 //! Enable IMU ADXL355 module
 * 
 */
#define MODULE_ENABLE_OLED // Enable OLED module
#define MODULE_ENABLE_MPU6050 // Enable IMU MPU6050 module
#define MODULE_ENABLE_ADXL355 // Enable IMU ADXL355 module

// Necessary Libraries
#include <stdio.h>

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

// OLED for Interfacing
#ifdef MODULE_ENABLE_OLED
#include "font.h"
#include "oled.h"
#endif

// MPU6050 for IMU
#ifdef MODULE_ENABLE_MPU6050
#include "mpu6050.h"
#endif

// ADXL355 for ACC 
#ifdef MODULE_ENABLE_ADXL355
#include "adxl355.h"
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