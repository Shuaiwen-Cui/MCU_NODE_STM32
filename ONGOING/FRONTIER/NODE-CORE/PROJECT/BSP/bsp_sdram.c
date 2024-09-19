/**
 * @file bsp_sdram.c
 * @author SHUAIWEN CUI (shuaiwencui AT gmail DOT com)
 * @brief This file is the source file for the bsp_sdram.c file
 * @version 1.0
 * @date 2024-07-16
 * @ref https://blog.csdn.net/Believeziwo/article/details/131372421
 */

/**
 * @name INCLUDES
 *
 */
#include "bsp_sdram.h"
#include "fmc.h"

/**
 * @name VARIABLES
 *
 */
static FMC_SDRAM_CommandTypeDef Command;
#define sdramHandle hsdram1 // defined in fmc.c

/**
 * @name FUNCTIONS
 *
 */

/**
  * @brief  initialize SDRAM in 6 steps
  * @param  None. 
  * @retval None.
  * ! This is the core for SDRAM initialization. CubeMX will do FMC initialization, then we need this function to do SDRAM initialization. After that, we can use SDRAM in the application layer.
  */
void SDRAM_InitSequence(void)
{
	uint32_t temp = 0;

	/* Step 1 ----------------------------------------------------------------*/
	/* CONFIGURE COMMAND: enable the clock for sdram */
	Command.CommandMode = FMC_SDRAM_CMD_CLK_ENABLE;
	Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
	Command.AutoRefreshNumber = 1;
	Command.ModeRegisterDefinition = 0;
	/* send command */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);

	/* delay for a while at least 200us */
	HAL_Delay(1); // 1ms>200us

	/* Step 3 ----------------------------------------------------------------*/
	/* CONFIGURE COMMAND: precharge all bank */
	Command.CommandMode = FMC_SDRAM_CMD_PALL;
	Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
	Command.AutoRefreshNumber = 1;
	Command.ModeRegisterDefinition = 0;
	/* send command */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);   

	/* Step 4 ----------------------------------------------------------------*/
	/* CONFIGURE COMMAND: auto refresh */   
	Command.CommandMode = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
	Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
	Command.AutoRefreshNumber = 8;
	Command.ModeRegisterDefinition = 0;
	/* send command */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);

	/* Step 5 ----------------------------------------------------------------*/
	/* CONFIGURE SDRAM LOAD MODE register */
	temp = (uint32_t)SDRAM_MODEREG_BURST_LENGTH_1          |
				   SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |
				   SDRAM_MODEREG_CAS_LATENCY_3           |
				   SDRAM_MODEREG_OPERATING_MODE_STANDARD |
				   SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

	/* CONFIGURE COMMAND: set SDRAM register */
	Command.CommandMode = FMC_SDRAM_CMD_LOAD_MODE;
	Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
	Command.AutoRefreshNumber = 1;
	Command.ModeRegisterDefinition = temp;
	/* send command */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);

	/* Step 6 ----------------------------------------------------------------*/
	/* CONFIGURE REFRESH COUNTER */
  /*
    (SDRAM refresh period / Number of rows）*SDRAM Clock Speed – 20
    = 64000(64 ms) / 8192*120MHz - 20
    = 917.2 ~ 918

    note: 64 / 8192 = 7.81us
  */
	/* CONFIGURE REFRESH RATE */
	HAL_SDRAM_ProgramRefreshRate(&sdramHandle, 918); 
}

/**
  * @brief  write data to SDRAM in "word" format
  * @param  pBuffer:  pointer to data
  * @param  uwWriteAddress: address to write in SDRAM
  * @param  uwBufferSize: size of data to write
  * @retval None.
  */
void SDRAM_WriteBuffer(uint32_t* pBuffer, uint32_t uwWriteAddress, uint32_t uwBufferSize)
{
  __IO uint32_t write_pointer = (uint32_t)uwWriteAddress;

  /* Disable write protection */
  HAL_SDRAM_WriteProtection_Disable(&hsdram1);
  /* Check the SDRAM state */
  while(HAL_SDRAM_GetState(&hsdram1) != RESET)
  {
  }

  /* write data to SDRAM by loops*/
  for (; uwBufferSize != 0; uwBufferSize--) 
  {
    /* write data to SDRAM */
    *(uint32_t *) (SDRAM_BANK_ADDR + write_pointer) = *pBuffer++;

    /* address increment */
    write_pointer += 4;
  }
    
}

/**
  * @brief  read data from SDRAM
  * @param  pBuffer: pointer to data
  * @param  ReadAddress: address to read in SDRAM
  * @param  uwBufferSize: size of data to read
  * @retval None.
  */
void SDRAM_ReadBuffer(uint32_t* pBuffer, uint32_t uwReadAddress, uint32_t uwBufferSize)
{
  __IO uint32_t write_pointer = (uint32_t)uwReadAddress;
  
   
  /* Check the SDRAM state */
  while ( HAL_SDRAM_GetState(&hsdram1) != RESET)
  {
  }
  
  /* read data from SDRAM */
  for(; uwBufferSize != 0x00; uwBufferSize--)
  {
   *pBuffer++ = *(__IO uint32_t *)(SDRAM_BANK_ADDR + write_pointer );
    
   /* address increment */
    write_pointer += 4;
  } 
}


/**
  * @brief  Test SDRAM
  * @param  None
  * @retval normal as 1, abnormal as 0
  */
uint8_t SDRAM_Test(void)
{
  /* counter for write data */
  uint32_t counter=0;
  
  /* 8 bit data */
  uint8_t ubWritedata_8b = 0, ubReaddata_8b = 0;  
  
  /* 16 bit data */
  uint16_t uhWritedata_16b = 0, uhReaddata_16b = 0; 

  /* 32 bit data */
  uint32_t uwWritedata_32b = 0, uwReaddata_32b = 0;
  
  SDRAM_INFO("TESTING SDRAM..., WRITE AND READ AS 8/16/32 BIT...");


  /* 8 bit data read and write*/
  
  /* reset SDRAM data to 0, W9825G6KH_SIZE is in 8 bit */
  for (counter = 0x00; counter < W9825G6KH_SIZE; counter++)
  {
    *(__IO uint8_t*) (SDRAM_BANK_ADDR + counter) = (uint8_t)0x0;
  }
  
  /* write data to SDRAM */
  for (counter = 0; counter < W9825G6KH_SIZE; counter++)
  {
    *(__IO uint8_t*) (SDRAM_BANK_ADDR + counter) = (uint8_t)(ubWritedata_8b + counter);
  }
  
  /* read data from SDRAM and check */
  for(counter = 0; counter<W9825G6KH_SIZE;counter++ )
  {
    ubReaddata_8b = *(__IO uint8_t*)(SDRAM_BANK_ADDR + counter);  // read data from SDRAM
    
    if(ubReaddata_8b != (uint8_t)(ubWritedata_8b + counter))      // check data, if not equal, return 0
    {
      SDRAM_ERROR("8 BIT DATA READ AND WRITE ERROR!");
      return -1;
    }
  }
	
  
  /* 16 bit data read and write*/
  
  /* reset SDRAM data to 0 */
  for (counter = 0x00; counter < W9825G6KH_SIZE/2; counter++)
  {
    *(__IO uint16_t*) (SDRAM_BANK_ADDR + 2*counter) = (uint16_t)0x00;
  }
  
  /* write data to SDRAM */
  for (counter = 0; counter < W9825G6KH_SIZE/2; counter++)
  {
    *(__IO uint16_t*) (SDRAM_BANK_ADDR + 2*counter) = (uint16_t)(uhWritedata_16b + counter);
  }
  
  /* read data from SDRAM and check */
  for(counter = 0; counter<W9825G6KH_SIZE/2;counter++ )
  {
    uhReaddata_16b = *(__IO uint16_t*)(SDRAM_BANK_ADDR + 2*counter);  // read data from SDRAM
    
    if(uhReaddata_16b != (uint16_t)(uhWritedata_16b + counter))      // check data, if not equal, return 0
    {
      SDRAM_ERROR("16 BIT DATA READ AND WRITE ERROR!");

      return -1;
    }
  }

  /* 32 bit data read and write*/
  /* reset SDRAM data to 0 */
  for (counter = 0x00; counter < W9825G6KH_SIZE/4; counter++)
  {
    *(__IO uint32_t*) (SDRAM_BANK_ADDR + 4*counter) = (uint32_t)0x00;
  }

  /* write data to SDRAM */
  for (counter = 0; counter < W9825G6KH_SIZE/4; counter++)
  {
    *(__IO uint32_t*) (SDRAM_BANK_ADDR + 4*counter) = (uint32_t)(uwWritedata_32b + counter);
  }
  
  /* read data from SDRAM and check */
  for(counter = 0; counter<W9825G6KH_SIZE/4;counter++ )
  {
    uwReaddata_32b = *(__IO uint32_t*)(SDRAM_BANK_ADDR + 4*counter);  // read data from SDRAM
    
    if(uwReaddata_32b != (uint32_t)(uwWritedata_32b + counter))      // check data, if not equal, return 0
    {
      SDRAM_ERROR("32 BIT DATA READ AND WRITE ERROR!");
      return -1;
    }
  }
  
  SDRAM_INFO("SDRAM READ AND WRITE TEST OK!"); 
  /* normal, return 0 */
  return 0;
  
}


/*********************************************END OF FILE**********************/
