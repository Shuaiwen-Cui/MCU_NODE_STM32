/**
 * @file filesystem.h
 * @author SHUAIWEN CUI (SHUAIWEN001 AT e DOT ntu DOT edu DOT sg)
 * @brief This file is for TinySHM Sensing.
 * @version 1.0
 * @date 2024-09-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef _FILESYSTEM_H_
#define _FILESYSTEM_H_

#include "main.h"
#include "setup.h"

/*
 ========================================================================== INITIALIZATION
 */

/**
 * @name FS_Check
 * @brief This function is to check the file system for the node. If not exist, create one.
 * 
 */
int FS_Check(void);

/**
 * @name Load_Config
 * @brief This function is to load the configurations into memory.
 */
int Load_Config(void);

/**
 * @name Node_FS_Init
 * @brief This function is to initialize the file system for the node.
 *
 */
int Node_FS_Init(void);

/*
 ========================================================================== COMMON OPERATION
 */

/**
 * @name Save_Data
 * @brief This function is to save the Data into the SD card.
 *
 */

int Save_Data(void);

#endif /* _FILESYSTEM_H_ */