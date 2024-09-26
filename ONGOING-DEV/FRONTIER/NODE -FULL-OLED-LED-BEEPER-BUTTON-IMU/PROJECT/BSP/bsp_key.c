/**
 * @file bsp_key.c
 * @author SHUAIWEN CUI (shuaiwencui at gmail dot com)
 * @brief 
 * @version 1.0
 * @date 2024-07-14
 */

#include "bsp_key.h"
#include "bsp_led.h"

#if KEY_MODE == 0
/**
 * @name WK_UP
 * @brief Read the level of the key interface
 * @param None
 * @retval 1: key pressed, 0: key not pressed
 */
uint8_t WK_UP(void)
{
	uint8_t key_status = 0;
	key_status=0;//if key is not pressed, return 0
	if(HAL_GPIO_ReadPin(WK_UP_GPIO_Port,WK_UP_Pin)==GPIO_PIN_RESET){// read the level of the key interface
		HAL_Delay(20);// delay 20ms to avoid jitter
		if(HAL_GPIO_ReadPin(WK_UP_GPIO_Port,WK_UP_Pin)==GPIO_PIN_RESET){ // read the level of the key interface again
			key_status=1;// if the key is pressed, return 1
		}
	}
	while(HAL_GPIO_ReadPin(WK_UP_GPIO_Port,WK_UP_Pin)==GPIO_PIN_RESET); // wait for the key to be released
	return key_status;
}

/**
 * @name KEY0
 * @brief Read the level of the key interface
 * @param None
 * @retval 1: key pressed, 0: key not pressed
 */
uint8_t KEY0(void)
{
	uint8_t key_status = 0;
	key_status=0;//if key is not pressed, return 0
	if(HAL_GPIO_ReadPin(KEY0_GPIO_Port,KEY0_Pin)==GPIO_PIN_RESET){// read the level of the key interface
		HAL_Delay(20);// delay 20ms to avoid jitter
		if(HAL_GPIO_ReadPin(KEY0_GPIO_Port,KEY0_Pin)==GPIO_PIN_RESET){ // read the level of the key interface again
			key_status=1;// if the key is pressed, return 1
		}
	}
	while(HAL_GPIO_ReadPin(KEY0_GPIO_Port,KEY0_Pin)==GPIO_PIN_RESET); // wait for the key to be released
	return key_status;
}

/**
 * @name KEY1
 * @brief Read the level of the key interface
 * @param None
 * @retval 1: key pressed, 0: key not pressed
 */
uint8_t KEY1(void)
{
	uint8_t key_status = 0;
	key_status=0;//if key is not pressed, return 0
	if(HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)==GPIO_PIN_RESET){// read the level of the key interface
		HAL_Delay(20);// delay 20ms to avoid jitter
		if(HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)==GPIO_PIN_RESET){ // read the level of the key interface again
			key_status=1;// if the key is pressed, return 1
		}
	}
	while(HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)==GPIO_PIN_RESET); // wait for the key to be released
	return key_status;
}

/**
 * @name KEY2
 * @brief Read the level of the key interface
 * @param None
 * @retval 1: key pressed, 0: key not pressed
 */
uint8_t KEY2(void)
{
	uint8_t key_status = 0;
	key_status=0;//if key is not pressed, return 0
	if(HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)==GPIO_PIN_RESET){// read the level of the key interface
		HAL_Delay(20);// delay 20ms to avoid jitter
		if(HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)==GPIO_PIN_RESET){ // read the level of the key interface again
			key_status=1;// if the key is pressed, return 1
		}
	}
	while(HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)==GPIO_PIN_RESET); // wait for the key to be released
	return key_status;
}

#else
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

    if(GPIO_Pin == WK_UP_Pin)
	{
		if(HAL_GPIO_ReadPin(WK_UP_GPIO_Port,WK_UP_Pin)==GPIO_PIN_SET)
		{
			LED_R(1), LED_G(1);
		}
	}
	else if(GPIO_Pin == KEY0_Pin)
	{
		if(HAL_GPIO_ReadPin(KEY0_GPIO_Port,KEY0_Pin)==GPIO_PIN_RESET)
		{
			LED_R(1), LED_G(0);
		}
	}
	else if(GPIO_Pin == KEY1_Pin)
	{
		if(HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)==GPIO_PIN_RESET)
		{
			LED_R(0), LED_G(1);
		}
	}
	else if(GPIO_Pin == KEY2_Pin)
	{
		if(HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)==GPIO_PIN_RESET)
		{
			LED_R(0), LED_G(0);
		}
	}
}

#endif