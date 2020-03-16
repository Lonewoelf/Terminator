/*
 * Motor.h
 *
 *  Created on: Mar 2, 2020
 *      Author: Madita
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#define PWM_MAX 100
#define AMOUNT_OF_MOTOR_CHANNELS 6

void moveRobot(float rotation, float x, float y); //Move robot to world view x,y with rotation.

#endif /* INC_MOTOR_H_ */
