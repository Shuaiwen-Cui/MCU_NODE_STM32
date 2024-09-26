/**
 * @file sensing.c
 * @author SHUAIWEN CUI (SHUAIWEN001 AT e DOT ntu DOT edu DOT sg)
 * @brief This file is for TinySHM Sensing.
 * @version 1.0
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */

/*
 ======================================== INCLUDES
 */

/* GENERAL */
#include "sensing.h"

/* I2C */
#include "i2c.h"

/* SPI */

/*
 ======================================== VARIABLES
 */

/*
 ======================================== FUNCTION DEFINITIONS
 */

/**
 * @name MPU6050_Gravity_Projection
 * @brief This function is for calculating the gravity projection of the MPU6050 for orientation calculation and compensation.
 * @param pIMU_Calibration: the pointer to the IMU_Calibration instance.
 *
 */

int MPU6050_Gravity_Projection(IMU_Calibration *pIMU_Calibration)
{
    int i;
    int sampling_rate = pIMU_Calibration->Calibration_Rate;
    int sampling_duration = pIMU_Calibration->Calibration_Duration;
    int sampling_points;
    float dt;
    float mean_x_g_proj = 0.0;
    float mean_y_g_proj = 0.0;
    float mean_z_g_proj = 0.0;
    float std_x_g_proj = 0.0;
    float std_y_g_proj = 0.0;
    float std_z_g_proj = 0.0;

    float *G_x_proj_data;
    float *G_y_proj_data;
    float *G_z_proj_data;

    float mean_square_sum = 1.0f;

    sampling_points = sampling_rate * sampling_duration + 1;
    dt = 1000.0 / sampling_rate; // ms

    G_x_proj_data = (float *)malloc(sampling_points * sizeof(float));
    G_y_proj_data = (float *)malloc(sampling_points * sizeof(float));
    G_z_proj_data = (float *)malloc(sampling_points * sizeof(float));

    // check if malloc fails
    if (G_x_proj_data == NULL || G_y_proj_data == NULL || G_z_proj_data == NULL)
    {
        printf("Error: Memory allocation failed.\n\r");
        return NODE_FAIL;
    }

    printf("Calculating MPU6050 Gravity Projection...\n\r");

    for (i = 0; i < sampling_points; i++)
    {
        MPU6050_Read_Accel(&hi2c2, &MPU6050);
        G_x_proj_data[i] = MPU6050.Ax;
        G_y_proj_data[i] = MPU6050.Ay;
        G_z_proj_data[i] = MPU6050.Az;
        HAL_Delay(dt);
    }

    if (0)
    {
        // print the data G_x_proj_data, G_y_proj_data, G_z_proj_data
        printf("Gravity Projection Data: \n\r");
        for (i = 0; i < sampling_points; i++)
        {
            printf("%12.8f %12.8f %12.8f\n\r", G_x_proj_data[i], G_y_proj_data[i], G_z_proj_data[i]);
        }
    }

#ifdef MODULE_ENABLE_CMSIS_DSP
    // calculate the average and standard deviation using CMSIS DSP

    arm_mean_f32(G_x_proj_data, sampling_points, &mean_x_g_proj);
    arm_mean_f32(G_y_proj_data, sampling_points, &mean_y_g_proj);
    arm_mean_f32(G_z_proj_data, sampling_points, &mean_z_g_proj);

    arm_std_f32(G_x_proj_data, sampling_points, &std_x_g_proj);
    arm_std_f32(G_y_proj_data, sampling_points, &std_y_g_proj);
    arm_std_f32(G_z_proj_data, sampling_points, &std_z_g_proj);

#else
    // calculate the average and standard deviation using basic math

    for (i = 0; i < sampling_points; i++)
    {
        mean_x_g_proj += G_x_proj_data[i] / sampling_points;
        mean_y_g_proj += G_y_proj_data[i] / sampling_points;
        mean_z_g_proj += G_z_proj_data[i] / sampling_points;
    }

    for (i = 0; i < sampling_points; i++)
    {
        std_x_g_proj += pow(G_x_proj_data[i] - mean_x_g_proj, 2);
        std_y_g_proj += pow(G_y_proj_data[i] - mean_y_g_proj, 2);
        std_z_g_proj += pow(G_z_proj_data[i] - mean_z_g_proj, 2);
    }

    std_x_g_proj = sqrt(std_x_g_proj / (sampling_points - 1));
    std_y_g_proj = sqrt(std_y_g_proj / (sampling_points - 1));
    std_z_g_proj = sqrt(std_z_g_proj / (sampling_points - 1));

#endif

    mean_square_sum = pow(mean_x_g_proj, 2) + pow(mean_y_g_proj, 2) + pow(mean_z_g_proj, 2);

    // modify the values of pIMU_Calibration
    pIMU_Calibration->Mean_AccX_G_Proj = mean_x_g_proj;
    pIMU_Calibration->Mean_AccY_G_Proj = mean_y_g_proj;
    pIMU_Calibration->Mean_AccZ_G_Proj = mean_z_g_proj;
    pIMU_Calibration->Std_AccX_G_Proj = std_x_g_proj;
    pIMU_Calibration->Std_AccY_G_Proj = std_y_g_proj;
    pIMU_Calibration->Std_AccZ_G_Proj = std_z_g_proj;
    pIMU_Calibration->Acc_Scale = sqrt(0.9999 / mean_square_sum);

    if (1)
    {
        // check the values in pIMU_Calibration
        printf("Mean_AccX_G_Proj: %12.8f\n\r", pIMU_Calibration->Mean_AccX_G_Proj);
        printf("Mean_AccY_G_Proj: %12.8f\n\r", pIMU_Calibration->Mean_AccY_G_Proj);
        printf("Mean_AccZ_G_Proj: %12.8f\n\r", pIMU_Calibration->Mean_AccZ_G_Proj);
        printf("Std_AccX_G_Proj: %12.8f\n\r", pIMU_Calibration->Std_AccX_G_Proj);
        printf("Std_AccY_G_Proj: %12.8f\n\r", pIMU_Calibration->Std_AccY_G_Proj);
        printf("Std_AccZ_G_Proj: %12.8f\n\r", pIMU_Calibration->Std_AccZ_G_Proj);
        printf("Acc_Scale: %12.8f\n\r", pIMU_Calibration->Acc_Scale);
    }

    // free
    free(G_x_proj_data);
    free(G_y_proj_data);
    free(G_z_proj_data);

    return NODE_SUCCESS;
}

/**
 * @name MPU6050_Read_Show
 * @brief This function is for reading and showing the MPU6050 data on OLED screen.
 * @param pIMU_Calibration: the pointer to the IMU_Calibration instance.
 *
 */
int MPU6050_Read_Show(IMU_Calibration *pIMU_Calibration)
{
    // Read Acc Data
    MPU6050_Read_All(&hi2c2, &MPU6050);

    // Print Acc Data
    // printf("Acceleration x:%12.8f \t y:%12.8f \t z:%12.8f\n", MPU6050.Ax, MPU6050.Ay, MPU6050.Az);

    // OLED UPDATING
    sprintf(acc_x_str, "%12.8f", MPU6050.Ax * pIMU_Calibration->Acc_Scale);
    sprintf(acc_y_str, "%12.8f", MPU6050.Ay * pIMU_Calibration->Acc_Scale);
    sprintf(acc_z_str, "%12.8f", MPU6050.Az * pIMU_Calibration->Acc_Scale);
    sprintf(IMU_Temp, "%4.2f Deg C", MPU6050.Temperature);

    // print acc_x_str, acc_y_str, acc_z_str, IMU_Temp
    // printf("acc_x_str: %s, acc_y_str: %s, acc_z_str: %s, IMU_Temp: %s\n", acc_x_str, acc_y_str, acc_z_str, IMU_Temp);

    // DISPLAY ACCELERATION
    OLED_NewFrame();

    OLED_PrintASCIIString(0, 0, "Accel X:", &afont8x6, OLED_COLOR_NORMAL);
    OLED_PrintASCIIString(50, 0, acc_x_str, &afont8x6, OLED_COLOR_NORMAL);
    OLED_PrintASCIIString(0, 12, "Accel Y:", &afont8x6, OLED_COLOR_NORMAL);
    OLED_PrintASCIIString(50, 12, acc_y_str, &afont8x6, OLED_COLOR_NORMAL);
    OLED_PrintASCIIString(0, 24, "Accel Z:", &afont8x6, OLED_COLOR_NORMAL);
    OLED_PrintASCIIString(50, 24, acc_z_str, &afont8x6, OLED_COLOR_NORMAL);
    OLED_PrintASCIIString(0, 36, "Temp:", &afont8x6, OLED_COLOR_NORMAL);
    OLED_PrintASCIIString(50, 36, IMU_Temp, &afont8x6, OLED_COLOR_NORMAL);

    OLED_ShowFrame();

    return NODE_SUCCESS;
}

/**
 * @name Triggering_Check
 * @brief This function is for checking the triggering status of the node.
 * @param pTriggering_Mechanism: the pointer to the Triggering_Mechanism instance.
 * @return int NODE_SUCCESS/NODE_FAIL
 *
 */
int Triggering_Check(Triggering_Mechanism *pTriggering_Mechanism)
{
    float activate_threshold_z = pTriggering_Mechanism->activate_threshold_z;
    int activate_duration = pTriggering_Mechanism->activate_duration;
    float inactivate_threshold_z = pTriggering_Mechanism->inactivate_threshold_z;
    int inactivate_duration = pTriggering_Mechanism->inactivate_duration;
    int cnt_activate = pTriggering_Mechanism->cnt_activate;
    int cnt_inactivate = pTriggering_Mechanism->cnt_inactivate;
    int activate_flag = pTriggering_Mechanism->activate_flag;
    int activate_led_flag = pTriggering_Mechanism->activate_led_flag;
    float acc;
    float avg_acc;
    float gap_acc;
    acc = MPU6050.Az * IMU_Calibration_Instance.Acc_Scale;
    avg_acc = IMU_Calibration_Instance.Mean_AccZ_G_Proj;
    gap_acc = fabs(acc - avg_acc);

    if (activate_flag == 0) // inactive
    {
        if (gap_acc > activate_threshold_z)
        {
            cnt_activate++;
            if (cnt_activate >= activate_duration)
            {
                activate_flag = 1;
                cnt_activate = 0;
            }
        }
        else
        {
            cnt_activate = 0;
        }
    }
    else // active
    {
        if (gap_acc < inactivate_threshold_z)
        {
            cnt_inactivate++;
            if (cnt_inactivate >= inactivate_duration)
            {
                activate_flag = 0;
                cnt_inactivate = 0;
            }
        }
        else
        {
            cnt_inactivate = 0;
        }
    }

    // LED
    if (activate_flag == 1)
    {
        // printf("Node activated!\n\r");
        activate_led_flag = 1;
#ifdef MODULE_ENABLE_RGB
        LED_RGB(1, 0, 0);
#endif
#ifdef MODULE_ENABLE_BUZZER
        Buzzer_On();
#endif
    }
    else
    {
        // printf("Node inactivated!\n\r");
        activate_led_flag = 0;

#ifdef MODULE_ENABLE_RGB
        LED_RGB(0, 0, 0);
#endif
#ifdef MODULE_ENABLE_BUZZER
        Buzzer_Off();
#endif
    }

    // output the numbers to pTriggering_Mechanism
    pTriggering_Mechanism->cnt_activate = cnt_activate;
    pTriggering_Mechanism->cnt_inactivate = cnt_inactivate;
    pTriggering_Mechanism->activate_flag = activate_flag;
    pTriggering_Mechanism->activate_led_flag = activate_led_flag;

    return NODE_SUCCESS;
}

/**
 * @name Update_Record_Num
 * @brief This function is used in record_sensing to update the record number. Path: /CONFIG/RECORD_NUM.cfg
 */
int Update_Record_Num(void)
{
    FRESULT fr;
    FILINFO finfo;
    UINT bw; // File write count

    // update the RECORD_NUM stored in the SD card in path: /CONFIG/RECORD_NUM.cfg. Overwrite it with "LAST = %d", record_num + 1
    char path[50] = "/CONFIG/RECORD_NUM.cfg";
    char buffer[30];

    record_num += 1;
    sprintf(buffer, "LAST = %d\n", record_num);

    // Open file for writing, create if doesn't exist
    fr = f_open(&SDFile, path, FA_WRITE | FA_CREATE_ALWAYS);
    if (fr != FR_OK)
    {
        printf("Error: Cannot open file %s for writing.\n", path);
        return NODE_FAIL;
    }

    // Write buffer to file
    fr = f_write(&SDFile, buffer, strlen(buffer), &bw);
    if (fr != FR_OK || bw != strlen(buffer))
    {
        printf("Error: Cannot write to file %s.\n", path);
        f_close(&SDFile);
        return NODE_FAIL;
    }

    // Sync file to ensure data is written to SD card
    fr = f_sync(&SDFile);
    if (fr != FR_OK)
    {
        printf("Error: Cannot sync file %s.\n", path);
        f_close(&SDFile);
        return NODE_FAIL;
    }

    // Close the file
    f_close(&SDFile);
    printf("Record number updated.\n\r");

    return NODE_SUCCESS;
}

/**
 * @name Record_Sensing
 * @brief This function is for recording the sensing data.
 *
 */
int Record_Sensing(void)
{
    // pass the configuration values to the meta data of the data structure
    int sampling_rate = sensing_rate;
    int sampling_duration = sensing_duration;

    // variables
    int i;
    float dt;
    int sampling_points;
    char progress[25];

    // calculate the sampling points
    sampling_points = sampling_rate * sampling_duration + 1;
    dt = 1000.0 / sampling_rate; // ms

    // pass the values to the meta data of the data structure
    LiftNode_Data.sampling_rate = sampling_rate;
    LiftNode_Data.sampling_duration = sampling_duration;
    LiftNode_Data.sampling_points = sampling_points;
    LiftNode_Data.dt = dt;

    // allocate memory for LiftNode_Data.ch01_data, LiftNode_Data.ch02_data, LiftNode_Data.ch03_data
    // LiftNode_Data.ch01_data = (float *)malloc(sampling_points * sizeof(float));
    // LiftNode_Data.ch02_data = (float *)malloc(sampling_points * sizeof(float));
    // LiftNode_Data.ch03_data = (float *)malloc(sampling_points * sizeof(float));

    LiftNode_Data.ch01_data = (float *)memory_alloc(sampling_points * sizeof(float));
    LiftNode_Data.ch02_data = (float *)memory_alloc(sampling_points * sizeof(float));
    LiftNode_Data.ch03_data = (float *)memory_alloc(sampling_points * sizeof(float));

    // sensing with iterations
    printf("Sensing...\n\r");

    LED_RGB(0, 0, 1);

    for (i = 0; i < sampling_points; i++)
    {
        // read the data
        // MPU6050_Read_All(&hi2c2, &MPU6050);
        MPU6050_Read_Accel(&hi2c2, &MPU6050);

        // save the data to the memory
        LiftNode_Data.ch01_data[i] = MPU6050.Ax * IMU_Calibration_Instance.Acc_Scale;
        LiftNode_Data.ch02_data[i] = MPU6050.Ay * IMU_Calibration_Instance.Acc_Scale;
        LiftNode_Data.ch03_data[i] = MPU6050.Az * IMU_Calibration_Instance.Acc_Scale;

        // print the data
        // printf("Ax: %12.8f, Ay: %12.8f, Az: %12.8f\n", LiftNode_Data.ch01_data[i], LiftNode_Data.ch02_data[i], LiftNode_Data.ch03_data[i]);

        if (i % sampling_rate == 0)
        {
            sprintf(progress, "%d/%d", i, sampling_points-1);
            // DISPLAY ACCELERATION
            OLED_NewFrame();

            OLED_PrintASCIIString(0, 0, "Progress:", &afont8x6, OLED_COLOR_NORMAL);
            OLED_PrintASCIIString(0, 24, progress, &afont8x6, OLED_COLOR_NORMAL);

            OLED_ShowFrame();
        }

        // delay
        HAL_Delay(dt);
    }

    OLED_NewFrame();
    OLED_PrintASCIIString(0, 0, "Done", &afont8x6, OLED_COLOR_NORMAL);
    OLED_PrintASCIIString(0, 24, "Waiting for next ...", &afont8x6, OLED_COLOR_NORMAL);
    OLED_ShowFrame();

    LED_RGB(1, 0, 0);

    // save the data to the SD card
    Save_Data();

    // update the RECORD_NUM stored in the SD card in path: /CONFIG/RECORD_NUM.cfg.
    Update_Record_Num();

    // free the memory
    memory_free(LiftNode_Data.ch01_data);
    memory_free(LiftNode_Data.ch02_data);
    memory_free(LiftNode_Data.ch03_data);

    button_trigger = 0;

    LED_RGB(0, 1, 0);

    return NODE_SUCCESS;
}
