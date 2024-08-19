# LED

## LED CIRCUIT DESIGN
![LED_CIRCUIT](led_circuit.png)

## CONFIGURE THE PIN
![LED_PIN](config_led.png)

### SELECT AND SET PIN MODE
According to the circuit design, select the corresponding pin PH7 and set the mode to "GPIO Output".

### GPIO SETTING
In the leftmost pane, select the "GPIO" tab and set the parameters for PH7 as shown in the figure below.

- GPIO OUTPUT LEVEL: LOW

!!! info
    As can be seen from the circuit design, low level output can light up the LED and high level output can turn off the LED.

- GPIO MODE: Output

Here, we set the pin mode to "Output" as we use it as a control for LED.

- GPIO PULL-UP/PULL-DOWN: PULL-UP

!!! info
    The pull-up resistor is used to ensure that the pin is in a high state when it is not connected to the ground.

- GPIO SPEED: Very High

!!! info
    The speed of the GPIO pin means the speed at which the pin changes from one state to another. Here, we set it to "Very High" to ensure that the LED can be turned on and off quickly. This is no strict requirement for the speed setting of the LED pin, but it is recommended to set it to "Very High" for better performance.

- USER LABEL: LED

!!! info
    The user label is used to mark the pin for easy identification. Here, we set it to "LED" to indicate that this pin is used to control the LED.

## GENERATE AND UPDATE CODE
Finally, let's generate the code to save the current progress and to make it ready for following programming steps. Click the 'Generate Code' button at the top right corner of the screen.

## PROGRAMMING IN KEIL

### INCORPORATE THE MODULE CODE

We have introduced how to transplant and incorporate the BSP code into the project, and that applies to each respective module. For transplantation:

1. Copy the module codes from the BSP project to the user project.
2. Add the module codes to the user project include path.
3. Add the module codes to the project items.
4. Include the header file of the module code in the user project.
5. Call the module function in the user project.

### CODE REVIEW - LED

Let's review the code for the LED module. This module is actually very simple, readers can refer to the code below for details.

#### **iled.h**

```c
/*
 * iled.h
 *
 *  Created on: June 07, 2024
 *      Author: SHUAIWEN CUI
 */

#ifndef ILED_H_
#define ILED_H_

#include "stm32h7xx_hal.h" // HAL library file declaration, replace it with the corresponding file according to the actual situation
#include "main.h" // IO definition and initialization function are in the main.c file, must be referenced

void LED(uint8_t state);// LED independent control function (0 is off, other values are on)
void LED_Toggle(void);// LED Toggle

#endif /* ILED_H_ */

```

#### **iled.c**

```c
/*
 * iled.c
 *
 *  Created on: June 07, 2024
 *      Author: SHUAIWEN CUI
 */

#include "iled.h"

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
```