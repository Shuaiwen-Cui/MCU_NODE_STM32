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
    int i;
    char filename[100];
    FRESULT fr;
    FILINFO finfo;
    UINT bw; // File write count

    /* STEP 1: check whether the folders and files are ready*/

    // go through the folder list and check if they exist
    for (i = 0; i < NUM_FOLDERS; i++)
    {
        fr = f_stat(liftnode_folders[i], &finfo);
        if (fr == FR_NO_FILE)
        {
            printf("Warning: Cannot find folder %s, creating one ...\n", liftnode_folders[i]);
            fr = f_mkdir(liftnode_folders[i]);
            if (fr != FR_OK)
            {
                printf("Error: Cannot create folder %s.\n", liftnode_folders[i]);
                return 1;
            }
            else
            {
                printf("Folder %s created.\n", liftnode_folders[i]);
            }
        }
        else if (fr != FR_OK)
        {
            printf("Error: Cannot access folder %s, code %d.\n", liftnode_folders[i], fr);
            return 1;
        }
        else
        {
            printf("Folder %s exists.\n", liftnode_folders[i]);
        }
    }

    // inside the folder CONFIG, go through the config_files list and check if they exist
    for (i = 0; i < NUM_CFG_FILES; i++)
    {
        sprintf(filename, "/%s/%s", liftnode_folders[0], config_files[i]); // only check the CONFIG folder, where the configuration files reside in.
        fr = f_stat(filename, &finfo);
        if (fr == FR_NO_FILE)
        {
            printf("Warning: Cannot find file %s, creating one ...\n", filename);
            fr = f_open(&SDFile, filename, FA_CREATE_ALWAYS | FA_WRITE); // always create a new file
            if (fr != FR_OK)
            {
                printf("Error: Cannot create file %s.\n", filename);
                return 1;
            }
            else
            {
                printf("File %s created.\n", filename);

                // if it is the RECORD_NUM file, write the initial value
                if (i == 2)
                {
                    const char *data = "LAST = 0\n";
                    UINT bytesWritten;
                    fr = f_write(&SDFile, data, strlen(data), &bytesWritten);
                    if (fr != FR_OK || bytesWritten != strlen(data))
                    {
                        printf("Error: Cannot write to file %s.\n", filename);
                        f_close(&SDFile);
                        return 1;
                    }
                    else
                    {
                        printf("Written 'LAST = 0' to %s.\n", filename);
                    }
                }

                // close the file
                f_close(&SDFile);
            }
        }
        else if (fr != FR_OK)
        {
            printf("Error: Cannot access file %s, code %d.\n", filename, fr);
            return 1;
        }
        else
        {
            printf("File %s exists.\n", filename);
        }
    }

    return 0;
}