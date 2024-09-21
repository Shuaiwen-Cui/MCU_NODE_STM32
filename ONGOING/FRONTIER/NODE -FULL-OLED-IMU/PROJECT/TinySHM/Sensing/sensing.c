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
 ======================================== FUNCTION DEFINITIONS - MPU6050
 */

/**
 * @name MPU6050_gravity_projection
 * @brief This function is for calculating the gravity projection of the MPU6050 for orientation calculation and compensation.
 * 
 */

int MPU6050_gravity_projection(IMU_Calibration *pIMU_Calibration)
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

    sampling_points = sampling_rate * sampling_duration + 1;
    dt = 1000.0 / sampling_rate; // ms
    
    G_x_proj_data = (float *)malloc(sampling_points * sizeof(float));
    G_y_proj_data = (float *)malloc(sampling_points * sizeof(float));
    G_z_proj_data = (float *)malloc(sampling_points * sizeof(float));


    for(i = 0; i < sampling_points; i++)
    {
        MPU6050_Read_All(&hi2c2, &MPU6050);
        G_x_proj_data[i] = MPU6050.Ax;
        G_y_proj_data[i] = MPU6050.Ay;
        G_z_proj_data[i] = MPU6050.Az;
        HAL_Delay(dt);
    }

    // print the data G_x_proj_data, G_y_proj_data, G_z_proj_data
    printf("Gravity Projection Data: \n\r");
    for(i = 0; i < sampling_points; i++)
    {
        printf("%12.8f %12.8f %12.8f\n\r", G_x_proj_data[i], G_y_proj_data[i], G_z_proj_data[i]);
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
    
    for(i = 0; i < sampling_points; i++)
    {
        mean_x_g_proj += G_x_proj_data[i] / sampling_points;
        mean_y_g_proj += G_y_proj_data[i] / sampling_points;
        mean_z_g_proj += G_z_proj_data[i] / sampling_points;
    }
    
    for(i = 0; i < sampling_points; i++)
    {
        std_x_g_proj += pow(G_x_proj_data[i] - mean_x_g_proj, 2);
        std_y_g_proj += pow(G_y_proj_data[i] - mean_y_g_proj, 2);
        std_z_g_proj += pow(G_z_proj_data[i] - mean_z_g_proj, 2);
    }
    
    std_x_g_proj = sqrt(std_x_g_proj / (sampling_points - 1));
    std_y_g_proj = sqrt(std_y_g_proj / (sampling_points - 1));
    std_z_g_proj = sqrt(std_z_g_proj / (sampling_points - 1));

#endif

    // modify the values of pIMU_Calibration
    pIMU_Calibration->Mean_AccX_G_Proj = mean_x_g_proj;
    pIMU_Calibration->Mean_AccY_G_Proj = mean_y_g_proj;
    pIMU_Calibration->Mean_AccZ_G_Proj = mean_z_g_proj;
    pIMU_Calibration->Std_AccX_G_Proj = std_x_g_proj;
    pIMU_Calibration->Std_AccY_G_Proj = std_y_g_proj;
    pIMU_Calibration->Std_AccZ_G_Proj = std_z_g_proj;

    // check the vaues in pIMU_Calibration
    printf("Mean_AccX_G_Proj: %12.8f\n\r", pIMU_Calibration->Mean_AccX_G_Proj);
    printf("Mean_AccY_G_Proj: %12.8f\n\r", pIMU_Calibration->Mean_AccY_G_Proj);
    printf("Mean_AccZ_G_Proj: %12.8f\n\r", pIMU_Calibration->Mean_AccZ_G_Proj);
    printf("Std_AccX_G_Proj: %12.8f\n\r", pIMU_Calibration->Std_AccX_G_Proj);
    printf("Std_AccY_G_Proj: %12.8f\n\r", pIMU_Calibration->Std_AccY_G_Proj);
    printf("Std_AccZ_G_Proj: %12.8f\n\r", pIMU_Calibration->Std_AccZ_G_Proj);

    // free 
    free(G_x_proj_data);
    free(G_y_proj_data);
    free(G_z_proj_data);
    
    return NODE_SUCCESS;
}


















int sensing(void)
{
    int i;
    int num_points = 64;
    double acc_data[num_points];

    printf("Sensing ... \n\r");

    for(i = 0; i < num_points; i++)
    {
        MPU6050_Read_All(&hi2c2, &MPU6050);
        acc_data[i] = MPU6050.Ax;
        HAL_Delay(100);
    }

    printf("Acceleration data: \n\r");
    for(i = 0; i < num_points; i++)
    {
        printf("%12.8f ", acc_data[i]);
        if( (i+1) % 8 == 0)
        {
            printf("\n\r");
        }
    }
    
    return 0;
}