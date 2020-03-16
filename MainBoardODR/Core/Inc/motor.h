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

void motorInit();
uint8_t motorGetSpeed(uint8_t motorID);          	//retrieves the current speed
bool motorBreak();		  					        //normal break, returns 0 if succeeded 1 if failed
bool motorBreakFast();			      				//emergency break, returns 0 if succeeded 1 if failed
bool motorSpeedUp(uint8_t factor, uint8_t motorID);	//Speeds up motor by factor, returns 0 if succeeded 1 if failed



#endif /* INC_MOTOR_H_ */
