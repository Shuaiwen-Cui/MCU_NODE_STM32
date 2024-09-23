/**
 * @file sensing.h
 * @author SHUAIWEN CUI (SHUAIWEN001 AT e DOT ntu DOT edu DOT sg)
 * @brief This file is for TinySHM Sensing.
 * @version 1.0
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef _SENSING_H_
#define _SENSING_H_

#include "main.h"
#include "setup.h"

/**
 * @name MPU6050_Gravity_Projection
 * @brief This function is for calculating the gravity projection of the MPU6050 for orientation calculation and compensation.
 * @param pIMU_Calibration: the pointer to the IMU_Calibration instance.
 *
 */

int MPU6050_Gravity_Projection(IMU_Calibration *pIMU_Calibration);

/**
 * @name MPU6050_Read_Show
 * @brief This function is for reading and showing the MPU6050 data on OLED screen.
 * @param pIMU_Calibration: the pointer to the IMU_Calibration instance.
 * 
 */
int MPU6050_Read_Show(IMU_Calibration *pIMU_Calibration);

#endif /* _SENSING_H_ */