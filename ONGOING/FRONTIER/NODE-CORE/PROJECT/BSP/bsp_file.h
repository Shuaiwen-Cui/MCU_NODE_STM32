/**
 * @file bsp_file.h
 * @author SHUAIWEN CUI (shuaiwencui AT gmail DOT com)
 * @brief This is the header file for the bsp_file.c file
 * @version 1.0
 * @date 2024-07-17
 * @ref https://blog.csdn.net/Mculover666/article/details/102688285；https://blog.csdn.net/qq_36561846/article/details/133808890
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _BSP_FILE_H_
#define _BSP_FILE_H_

/**
 * @name INCLUDES
 */

#include "stm32h7xx.h"
#include "main.h"
#include "ff.h"         // FATFS main header file
#include "diskio.h"     // Disk I/O header file
#include "fatfs.h"      // FATFS configuration header file (if using STM32CubeMX)
#include "ff_gen_drv.h" // Generic driver header file
#include "ffconf.h"
#include "stdio.h"

/* Define custom storage device */
/* Number of bytes per sector for user storage device */
#define User_Sector 512
/* FatFs object for user storage device */
#define User_FatFs SDFatFS
/* Volume path for user storage device */
#define User_SDPath SDPath
 
/*functions*/
void Mount_FatFs(void);
void FatFs_GetDiskInfo(void);
void FatFs_ScanDir(const TCHAR* PathName);
void FatFs_ReadTXTFile(TCHAR *filename);
void FatFs_WriteTXTFile(TCHAR *filename,uint16_t year, uint8_t month, uint8_t day);
void FatFs_GetFileInfo(TCHAR *filename);
void FatFs_DeleteFile(TCHAR *filename);
void FatFs_PrintfFileDate(WORD date, WORD time);

uint8_t BSP_SD_ReadBlocks_DMA(uint32_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks);
uint8_t BSP_SD_WriteBlocks_DMA(uint32_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks);
#endif /* _BSP_FILE_H_ */
