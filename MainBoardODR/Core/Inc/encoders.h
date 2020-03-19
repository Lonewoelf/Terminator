/*
 * encoder.h
 *
 *  Created on: Mar 11, 2020
 *      Author: Madita
 */

#include "main.h"

#ifndef INC_ENCODERS_H_
#define INC_ENCODERS_H_

#define AMOUNT_OF_ENCODERS 3

uint16_t timerValue;
uint32_t encoderA1, encoderA2, encoderA3, encoderB1, encoderB2, encoderB3;
uint32_t speed1, speed2, speed3;

TIM_HandleTypeDef htim1;

void MX_TIM1_Init(void);

void encoderInit();
uint32_t encoderCalculateSpeed(uint32_t time, uint32_t timePrev);

#endif /* INC_ENCODERS_H_ */
