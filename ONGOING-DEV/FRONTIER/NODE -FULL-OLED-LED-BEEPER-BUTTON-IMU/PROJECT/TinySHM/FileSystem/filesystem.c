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


/*
 ========================================================================== INITIALIZATION
 */

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

/*
 ========================================================================== COMMON OPERATION
 */

/**
 * @name Save_Data
 * @brief This function is to save the Data into the SD card.
 *
 */

int Save_Data(void)
{
    /* VARIABLES */
    int i, j;
    char data_folder[20];
    char data_filename[50]; // to be constructed
    char meta_data_filename[50]; // to be constructed
    char data_path[100]; // to be constructed
    char meta_data_path[100]; // to be constructed

    char content[100];

    FRESULT fr;
    FILINFO finfo;
    UINT bw; // File write count
    UINT br; // File read count

    /* FILENAME & PATH */
    sprintf(data_folder, "%s", liftnode_folders[1]); // DATA folder
    printf("Data folder: %s\n", data_folder);

    sprintf(data_filename, "%s_%d.csv", "Node_Data", record_num + 1); // DATA file
    printf("Data filename: %s\n", data_filename);

    sprintf(meta_data_filename, "%s_%d.csv", "Node_Meta_Data", record_num + 1); // META DATA file
    printf("Meta Data filename: %s\n", meta_data_filename);

    sprintf(data_path, "/%s/%s", data_folder, data_filename); // DATA path
    printf("Data path: %s\n", data_path);

    sprintf(meta_data_path, "/%s/%s", data_folder, meta_data_filename); // META DATA path
    printf("Meta Data path: %s\n", meta_data_path);

    /* WRITE META DATA */

    // Meta Data Saving, save LiftNode_Data.sampling_rate, LiftNode_Data.sampling_duration, LiftNode_Data.sampling_points, LiftNode_Data.dt to the file, each in a row
    fr = f_open(&SDFile, meta_data_path, FA_CREATE_ALWAYS | FA_WRITE); // always create a new file
    if (fr != FR_OK)
    {
        printf("Error: Cannot create file %s.\n", meta_data_path);
        return NODE_FAIL;
    }
    else
    {
        printf("File %s created.\n", meta_data_path);

        // Write the meta data
        for (i = 0; i < 4; i++)
        {
            switch (i)
            {
            case 0:
                sprintf(content, "SAMPLING RATE = %d\n", LiftNode_Data.sampling_rate);
                break;
            case 1:
                sprintf(content, "SAMPLING DURATION = %d\n", LiftNode_Data.sampling_duration);
                break;
            case 2:
                sprintf(content, "SAMPLING POINTS = %d\n", LiftNode_Data.sampling_points);
                break;
            case 3:
                sprintf(content, "SAMPLING INTERVAL (ms) = %f\n", LiftNode_Data.dt);
                break;
            default:
                break;
            }

            fr = f_write(&SDFile, content, strlen(content), &bw);
            if (fr != FR_OK || bw != strlen(content))
            {
                printf("Error: Cannot write to file %s.\n", meta_data_path);
                f_close(&SDFile);
                return NODE_FAIL;
            }
            else
            {
                // printf("Written '%s' to %s.\n", content, meta_data_path);
            }
        }

        // close the file
        f_close(&SDFile);
    }

    /* WRITE DATA */ 

    // write LiftNode_Data.ch01_data, LiftNode_Data.ch02_data, LiftNode_Data.ch03_data to the file, in 3 columns, each row stands for a time point, columns are separated by ',': %f,%f,%f\n
    fr = f_open(&SDFile, data_path, FA_CREATE_ALWAYS | FA_WRITE); // always create a new file
    if (fr != FR_OK)
    {
        printf("Error: Cannot create file %s.\n", data_path);
        return NODE_FAIL;
    }
    else
    {
        printf("File %s created.\n", data_path);

        // Write the data
        for (i = 0; i < LiftNode_Data.sampling_points; i++)
        {
            sprintf(content, "%12.8f,%12.8f,%12.8f\n", LiftNode_Data.ch01_data[i], LiftNode_Data.ch02_data[i], LiftNode_Data.ch03_data[i]);

            fr = f_write(&SDFile, content, strlen(content), &bw);
            if (fr != FR_OK || bw != strlen(content))
            {
                printf("Error: Cannot write to file %s.\n", data_path);
                f_close(&SDFile);
                return NODE_FAIL;
            }
            else
            {
                // printf("Written '%s' to %s.\n", content, data_path);
            }
        }

        // close the file
        f_close(&SDFile);
    }

    return NODE_SUCCESS;
}