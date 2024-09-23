/**
 * @file bsp_memory.h
 * @author SHUAIWEN CUI (shuaiwencui AT gmail DOT com)
 * @brief This is the header file for the memory management module.
 * @version 1.0
 * @date 2024-06-30
 * @ref ALIENTEK memory.h & memory.c for STM32H7xx
 * @copyright Copyright (c) 2024
 *
 *
 */

#ifndef _BSP_MEMORY_H_
#define _BSP_MEMORY_H_

/**
 * @name INCLUDES
 */
#include "stm32h7xx.h"
#include <stddef.h>
#include <stdint.h>
#include "bsp_usart.h"
#include "bsp_sdram.h"

/**
 * @name FUNCTION PROTOTYPES
 */
/**
 * @name memory_init
 * @brief Initialize the memory management module
 * @param None
 * @retval None
 */
void memory_init(void);

/**
 * @name memory_alloc
 * @brief Allocate memory
 * @param size The size of the memory to allocate
 * @return void*
 */
void *memory_alloc(size_t size);

/**
 * @name memory_free
 * @brief Free memory
 * @param ptr The pointer to the memory to free
 * @retval None
 */
void memory_free(void *ptr);

/**
 * @name memory_management_test
 * @brief This function is for memory management test: allocate memory for a given length, set the values, print the values, and free the memory.
 */
int memory_management_test(void);


#endif /* _BSP_MEMORY_H_ */
