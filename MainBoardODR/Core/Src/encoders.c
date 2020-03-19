/*
 * encoders.c
 *
 *  Created on: Mar 11, 2020
 *      Author: Madita
 */
#include "encoders.h"

static uint32_t temp1 = 0, temp2 = 0, temp3 = 0;
static uint32_t speed1 = 0, speed2 = 0, speed3 = 0;

void encoderInit(){
	timerValue = 0;
	encoderA1 = 0;
	encoderA2 = 0;
	encoderA3 = 0;
	encoderB1 = 0;
	encoderB2 = 0;
	encoderB3 = 0;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	timerValue = TIM1->CNT;

	switch(GPIO_Pin){

	case ENCODER_A1_Pin:
		temp1 = encoderA1;
		encoderA1 = timerValue;
		encoderCalculateSpeed(encoderA1, temp1);

	case ENCODER_A2_Pin:
		temp2 = encoderA2;
		encoderA2 = timerValue;
		encoderCalculateSpeed(encoderA2, temp2);

	case ENCODER_A3_Pin:
		temp3 = encoderA3;
		encoderA3 = timerValue;
		encoderCalculateSpeed(encoderA3, temp3);

//	case ENCODER_B1_Pin:
//
//	case ENCODER_B2_Pin:
//
//	case ENCODER_B3_Pin:

	}

	encoderCalculateOverallSpeed(speed1, speed2, speed3);
}

uint32_t encoderCalculateSpeed(uint32_t time, uint32_t timePrev){ // m/s
	return (WHEEL_SIZE / (timePrev - time));
}

uint32_t encoderCalculateOverallSpeed(uint32_t speed1, uint32_t speed2, uint32_t speed3){ // m/s
	return ((speed1 + speed2 + speed3) / AMOUNT_OF_ENCODERS);
}
