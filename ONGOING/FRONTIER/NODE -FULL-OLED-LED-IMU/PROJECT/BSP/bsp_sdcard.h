/**
 * @file bsp_sdcard.h
 * @author SHUAIWEN CUI (shuaiwencui AT gmail DOT com)
 * @brief This is the header file for the bsp_sdcard.c file
 * @version 1.0
 * @date 2024-07-16
 * @ref https://blog.csdn.net/mculover666/article/details/100555620
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _BSP_SDCARD_H_
#define _BSP_SDCARD_H_

/**
 * @name INCLUDES
 */

#include "stm32h7xx.h"

/**
 * @name MACROS
 */


/**
 * @name VARIABLES
 *
 */
extern uint8_t read_buf[512];
extern uint8_t write_buf[512];

/**
 * @name FUNCTION PROTOTYPES
 */
/**
 * @name SD_Init
 * @brief SD card initialization, this function handles the part that not processed by CUBEMX.
 */
int SD_Init(void);

/**
 * @name SD_Test
 * @brief Display the SD card information for SD card testing
 * 
 */
int SD_Test(void);

#endif /* _BSP_SDCARD_H_ */


