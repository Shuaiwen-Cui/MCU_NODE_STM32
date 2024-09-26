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

/*
 ======================================== INCLUDES
 */

#include "main.h"
#include "setup.h"

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

int MPU6050_Gravity_Projection(IMU_Calibration *pIMU_Calibration);

/**
 * @name MPU6050_Read_Show
 * @brief This function is for reading and showing the MPU6050 data on OLED screen.
 * @param pIMU_Calibration: the pointer to the IMU_Calibration instance.
 * 
 */
int MPU6050_Read_Show(IMU_Calibration *pIMU_Calibration);

/**
 * @name Triggering_Check
 * @brief This function is for checking the triggering status of the node.
 * @param pTriggering_Mechanism: the pointer to the Triggering_Mechanism instance.
 * @return int NODE_SUCCESS/NODE_FAIL
 * 
 */
int Triggering_Check(Triggering_Mechanism *pTriggering_Mechanism);

/**
 * @name Update_Record_Num
 * @brief This function is used in record_sensing to update the record number. Path: /CONFIG/RECORD_NUM.cfg
 */
int Update_Record_Num(void);

/**
 * @name Record_Sensing
 * @brief This function is for recording the sensing data.
 *
 */
int Record_Sensing(void);

#endif /* _SENSING_H_ */