/*
 * bsp_led.c
 *
 *  Created on: June 07, 2024
 *      Author: SHUAIWEN CUI
 */

#include "bsp_led.h"

void LED(uint8_t state) // LED R independent control function (0 is off, other values are on)
{

	if (state)
	{
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
	}
}

void LED_Toggle(void)
{
	int state = HAL_GPIO_ReadPin(LED_GPIO_Port, LED_Pin);
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 1 - state);
}


