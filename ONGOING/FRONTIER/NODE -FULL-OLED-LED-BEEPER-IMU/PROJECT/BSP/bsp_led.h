/*
 * bsp_led.h
 *
 *  Created on: June 07, 2024
 *      Author: SHUAIWEN CUI
 */

#ifndef _BSP_LED_H_
#define _BSP_LED_H_

#include "stm32h7xx_hal.h" // HAL library file declaration, replace it with the corresponding file according to the actual situation
#include "main.h" // IO definition and initialization function are in the main.c file, must be referenced

void LED(uint8_t state);// LED independent control function (0 is off, other values are on)
void LED_Toggle(void);// LED Toggle

#endif /* _BSP_LED_H_ */
