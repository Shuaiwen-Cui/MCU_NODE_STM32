/**
 * @file filesystem.c
 * @author SHUAIWEN CUI (SHUAIWEN001 AT e DOT ntu DOT edu DOT sg)
 * @brief This file is for TinySHM Sensing.
 * @version 1.0
 * @date 2024-09-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "filesystem.h"

/**
 * @name Node_FS_Init
 * @brief This function is to initialize the file system for the node.
 *
 */
int Node_FS_Init(void)
{
    /* STEP 1: check whether the folders and files are ready*/
    fr = f_stat("/CONFIG", &finfo);
    if (fr == FR_NO_FILE)
    {
        printf("Warning: Cannot find folder /CONFIG, creating one ...\n");
        fr = f_mkdir("/CONFIG");
        if (fr != FR_OK)
        {
            printf("Error: Cannot create folder /CONFIG.\n");
            return 1;
        }
        else
        {
            printf("Folder /CONFIG created.\n");
        }
    }
    else if (fr != FR_OK)
    {
        printf("Error: Cannot access folder /CONFIG, code %d.\n", fr);
        return 1;
    }
    else
    {
        printf("Folder /CONFIG exists.\n");
    }

    fr = f_stat("/DATA", &finfo);
    if (fr == FR_NO_FILE)
    {
        printf("Warning: Cannot find folder /DATA, creating one ...\n");
        fr = f_mkdir("/DATA");
        if (fr != FR_OK)
        {
            printf("Error: Cannot create folder /DATA.\n");
            return 1;
        }
        else
        {
            printf("Folder /DATA created.\n");
        }
    }
    else if (fr != FR_OK)
    {
        printf("Error: Cannot access folder /DATA, code %d.\n", fr);
        return 1;
    }
    else
    {
        printf("Folder /DATA exists.\n");
    }

    return 0;
}