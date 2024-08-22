/**
 * @file bsp_init.h
 * @author SHUAIWEN CUI (SHUAIWEN001 AT e DOT ntu DOT edu DOT sg)
 * @brief This file contains the headers of the BSP initialization functions.
 * @version 1.0
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef BSP_INIT_H
#define BSP_INIT_H

#define BSP_INIT_SUCCESS 0
#define BSP_INIT_FAIL 1

// #define BSP_INIT_TEST // test required for the BSP initialization, comment this out to disable the test

/**
 * @name Modules To Be Enabled
 * @brief This section is to determine the modules to be included in the project
 * ! This is where you configure the modules to be included in the project
 * @param MODULE_ENABLE_LED //! Enable LED module
 * @param MODULE_ENABLE_KEY //! Enable Key module (No use in this project, do not enable it)
 * @param MODULE_ENABLE_USART1 //! Enable USART1 module for serial communication
 * @param MODULE_ENABLE_SDRAM //! Enable SDRAM module to use external RAM for computation
 * @param MODULE_ENABLE_MEMORY //! Enable Memory module - for memory management on SDRAM
 * @param MODULE_ENABLE_SDCARD //! Enable SD Card module test - for SD Card basic io. !!! This module can not be used together with MODULE_ENABLE_FILE
 * @param MODULE_ENABLE_FILE //! Enable File module test - for file operations on SD Card !!! This module can not be used together with MODULE_ENABLE_SDCARD
 */

#define MODULE_ENABLE_LED // Enable LED module
// #define MODULE_ENABLE_KEY  // Enable Key module
#define MODULE_ENABLE_USART1 // Enable USART1 module
#define MODULE_ENABLE_SDRAM  // Enable SDRAM module
#define MODULE_ENABLE_MEMORY // Enable Memory module - for memory management on SDRAM
// #define MODULE_ENABLE_SDCARD // Enable SD Card module
#define MODULE_ENABLE_FILE   // Enable File module - for file operations on SD Card

/**
 * @name Include Files
 *
 */
#include <stdio.h>
#ifdef MODULE_ENABLE_LED

#include "iled.h"

#endif

#ifdef MODULE_ENABLE_KEY

#include "ikey.h"

#endif

#ifdef MODULE_ENABLE_USART1 //! Note - Do rember to check the MicroLib option in the project settings

#include <stdio.h>
#include "iusart.h"

#endif

#ifdef MODULE_ENABLE_SDRAM

#include "isdram.h"

#endif

#ifdef MODULE_ENABLE_MEMORY

#include "imemory.h"

#endif

#ifdef MODULE_ENABLE_SDCARD

#include "isdcard.h"

#endif

#ifdef MODULE_ENABLE_FILE

#include "ifile.h"

#endif

/**
 * @name Function Prototypes
 *
 */

// The BSP initialization function - including all the initialization functions
int BSP_Init();

#ifdef MODULE_ENABLE_USART1
// IO retargetting
int fputc(int ch, FILE *f);
int fgetc(FILE *f);
#endif

#endif /* BSP_INIT_H */