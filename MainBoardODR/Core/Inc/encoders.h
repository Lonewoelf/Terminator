/*
 * encoder.h
 *
 *  Created on: Mar 11, 2020
 *      Author: Madita
 */

#include "main.h"

#ifndef INC_ENCODERS_H_
#define INC_ENCODERS_H_

#define PULSES_PER_REVOLUTION 500.0
#define GEAR_REDUCTION 16.0
#define AMOUNT_OF_ENCODERS 3
#define TIM6_PERIOD 10000
#define TIM6_BASEFREQ 1000000

uint16_t timerValue;
uint32_t encoderA1, encoderA2, encoderA3, encoderB1, encoderB2, encoderB3;
float speed1, speed2, speed3;

TIM_HandleTypeDef htim6;

void MX_TIM6_Init(void);

void encoderInit();
uint32_t encoderCalculateSpeed(uint32_t time, uint32_t timePrev);

#endif /* INC_ENCODERS_H_ */
