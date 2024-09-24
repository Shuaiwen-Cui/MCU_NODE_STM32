/**
 * @file buzzer.h
 * @author SHUAIWEN CUI (SHUAIWEN001 AT e DOT ntu DOT edu DOT sg)
 * @brief This file is for buzzer control function declaration.
 * @version 1.0
 * @date 2024-09-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "buzzer.h"

/**
 * @name Buzzer_On
 * @brief Turn on the buzzer
 */
void Buzzer_On(void)
{
    HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_SET);
}

/**
 * @name Buzzer_Off
 * @brief Turn off the buzzer
 */
void Buzzer_Off(void)
{
    HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
}

/**
 * @name Buzzer_Toggle
 * @brief Toggle the buzzer
 */
void Buzzer_Toggle(void)
{
    HAL_GPIO_TogglePin(BUZZER_GPIO_Port, BUZZER_Pin);
}

/**
 * @name Buzzer_Beep
 * @brief Make the buzzer beep for a specified duration
 */
void Buzzer_Beep(uint32_t duration_ms)
{
    Buzzer_On();
    HAL_Delay(duration_ms); // Delay for the specified duration
    Buzzer_Off();
}
