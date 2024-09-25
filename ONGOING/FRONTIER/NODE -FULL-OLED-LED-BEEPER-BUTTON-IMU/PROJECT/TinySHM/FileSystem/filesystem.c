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
 * @name FS_Check
 * @brief This function is to check the file system for the node. If not exist, create one.
 * 
 */
int FS_Check(void)
{
    int i;
    char filename[50];
    char buffer[50];
    FRESULT fr;
    FILINFO finfo;
    UINT bw; // File write count
    UINT br; // File read count

    /* check whether the folders and files are ready*/

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
                return NODE_FAIL;
            }
            else
            {
                printf("Folder %s created.\n", liftnode_folders[i]);
            }
        }
        else if (fr != FR_OK)
        {
            printf("Error: Cannot access folder %s, code %d.\n", liftnode_folders[i], fr);
            return NODE_FAIL;
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
                return NODE_FAIL;
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
                        return NODE_FAIL;
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
            return NODE_FAIL;
        }
        else
        {
            printf("File %s exists.\n", filename);
        }
    }

    return NODE_SUCCESS;
}

/**
 * @name Load_Config
 * @brief This function is to load the configurations into memory.
 */
int Load_Config(void)
{
    int i;
    char filename[50];
    char buffer[50];
    int offset;
    FRESULT fr;
    FILINFO finfo;
    UINT bw; // File write count
    UINT br; // File read count

    /* load the configurations into memory*/

    // RECORD_NUM loading
    sprintf(filename, "/%s/%s", liftnode_folders[0], config_files[2]);

    // Open the file first to ensure it can be read
    fr = f_open(&SDFile, filename, FA_READ);
    if (fr == FR_OK)
    {
        // Load content into buffer
        fr = f_read(&SDFile, buffer, sizeof(buffer) - 1, &br);
        if (fr == FR_OK && br > 0)
        {
            buffer[br] = '\0'; // Ensure the string is terminated with '\0'

            // Find "LAST = " and then extract the number behind it
            char *last_str = strstr(buffer, "LAST = ");
            if (last_str != NULL)
            {
                offset = strlen("LAST = ");
                record_num = atoi(last_str + offset); // Skip the "LAST = " and convert the number to integer
                printf("Loaded record number: %d\n", record_num);
            }
            else
            {
                printf("Error: 'LAST = ' not found in the file.\n");
            }
        }
        else
        {
            printf("Error: Failed to read the file %s.\n", filename);
        }

        // Close the file
        f_close(&SDFile);
    }
    else
    {
        printf("Error: Cannot open file %s for reading.\n", filename);
        return NODE_FAIL;
    }

    return NODE_SUCCESS;
}

/**
 * @name Node_FS_Init
 * @brief This function is to initialize the file system for the node.
 *
 */
int Node_FS_Init(void)
{
    // Step 1: FS Check
    if(FS_Check() != NODE_SUCCESS)
    {
        return NODE_FAIL;
    }

    // Step 2：Load Configurations
    if(Load_Config() != NODE_SUCCESS)
    {
        return NODE_FAIL;
    }

    return NODE_SUCCESS;
}
