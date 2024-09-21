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

int MPU6050_gravity_projection(IMU_Calibration *pIMU_Calibration);
int sensing(void);

#endif /* _SENSING_H_ */