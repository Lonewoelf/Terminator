/*
 * Motor.h
 *
 *  Created on: Mar 2, 2020
 *      Author: Madita
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_
#define WHEEL_CENTER_RADIUS 120.0
#define WHEEL_DIAMETER 79.0
#define WHEEL_CIRCOMFERENCE WHEEL_DIAMETER*M_PI
#define PWM_MAX 100
#define AMOUNT_OF_MOTOR_CHANNELS 6
#define MAX_SPEED 25.0

#include "main.h"

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

int8_t pwm[AMOUNT_OF_MOTOR_CHANNELS];


void initMotors();
void MX_TIM2_Init(void);
void MX_TIM3_Init(void);
void moveRobot(float OM, float Theta, float VxW, float VyW); //Move robot to world view x,y with rotation.
void demoMotors();

#endif /* INC_MOTOR_H_ */
