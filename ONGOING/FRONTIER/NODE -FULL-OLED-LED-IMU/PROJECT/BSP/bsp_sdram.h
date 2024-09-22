/**
 * @file bsp_sdram.h
 * @author SHUAIWEN CUI (shuaiwencui AT gmail DOT com)
 * @brief This file is the header file for the bsp_sdram.c file
 * @version 1.0
 * @date 2024-07-16
 * @ref https://blog.csdn.net/Believeziwo/article/details/131372421
 */
#ifndef _BSP_SDRAM_H_
#define _BSP_SDRAM_H_

/**
 * @name INCLUDES
 *
 */
#include "stm32h7xx.h"
#include <stdio.h>

/**
 * @name MACROS
 *
 */
#define W9825G6KH_SIZE (32 * 1024 * 1024) // 32M Bytes W9825G6
#define FMC_BANK_SDRAM FMC_Bank1_SDRAM
#define FMC_COMMAND_TARGET_BANK FMC_SDRAM_CMD_TARGET_BANK1
#define SDRAM_BANK_ADDR ((uint32_t)0xC0000000)
#define SDRAM_TIMEOUT ((uint32_t)0xFFFF)
#define SDRAM_MODEREG_BURST_LENGTH_1 ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2 ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4 ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8 ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2 ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3 ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE ((uint16_t)0x0200)

#define SDRAM_DEBUG_ON 1
#define SDRAM_INFO(fmt, arg...) printf("[NODE INITIALIZATION] " fmt "\n", ##arg)
#define SDRAM_ERROR(fmt, arg...) printf("[NODE INITIALIZATION] " fmt "\n", ##arg)
#define SDRAM_DEBUG(fmt, arg...)                                       \
    do                                                                 \
    {                                                                  \
        if (SDRAM_DEBUG_ON)                                            \
            printf("[NODE INITIALIZATION] [%d]" fmt "\n", __LINE__, ##arg); \
    } while (0)

/**
 * @name FUNCTION PROTOTYPES
 *
 */
void SDRAM_InitSequence(void);
void SDRAM_WriteBuffer(uint32_t *pBuffer, uint32_t uwWriteAddress, uint32_t uwBufferSize);
void SDRAM_ReadBuffer(uint32_t *pBuffer, uint32_t uwReadAddress, uint32_t uwBufferSize);
uint8_t SDRAM_Test(void);

#endif /* _BSP_SDRAM_H_ */
