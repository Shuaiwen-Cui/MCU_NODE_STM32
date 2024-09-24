/**
 * @file led_rgb.c
 * @author SHUAIWEN CUI (SHUAIWEN001 AT e DOT ntu DOT edu DOT sg)
 * @brief This file is for RGB LED control function declaration.
 * @version 1.0
 * @date 2024-09-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "led_rgb.h"

void LED_RGB(int LED_R, int LED_G, int LED_B) // LED RGB independent control function (0 is off, other values are on)
{
    if (LED_R)
    {
        HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
    }

    if (LED_G)
    {
        HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
    }

    if (LED_B)
    {
        HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_RESET);
    }
}

void LED_RGB_Toggle(void)
{
    int state_R = HAL_GPIO_ReadPin(LED_R_GPIO_Port, LED_R_Pin);
    HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, 1 - state_R);

    int state_G = HAL_GPIO_ReadPin(LED_G_GPIO_Port, LED_G_Pin);
    HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1 - state_G);

    int state_B = HAL_GPIO_ReadPin(LED_B_GPIO_Port, LED_B_Pin);
    HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1 - state_B);
}