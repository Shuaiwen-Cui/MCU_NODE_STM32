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

#include "sensing.h"
#include "i2c.h"

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