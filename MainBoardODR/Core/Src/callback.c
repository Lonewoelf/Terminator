/*
 * callback.c
 *
 *  Created on: Mar 19, 2020
 *      Author: Jonathan
 */

#include "motor.h"
#include "encoders.h"
#include "main.h"

uint8_t pwmCounter = 0;

GPIO_TypeDef* pwmPinOutBank[AMOUNT_OF_MOTOR_CHANNELS] = {GPIOB, GPIOA, GPIOB, GPIOB, GPIOA, GPIOA};

uint16_t pwmPinOut[AMOUNT_OF_MOTOR_CHANNELS] = {
		MOTOR_IN_1_1_Pin,
		MOTOR_IN_1_2_Pin,
		MOTOR_IN_2_1_Pin,
		MOTOR_IN_2_2_Pin,
		MOTOR_IN_3_1_Pin,
		MOTOR_IN_3_2_Pin};

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {



	if (htim->Instance == TIM2) {
		pwmCounter++;

		if (pwmCounter > PWM_MAX) {
			pwmCounter = 1;
		}

		for (uint8_t pwmOutput = 0; pwmOutput < AMOUNT_OF_MOTOR_CHANNELS; pwmOutput++){
			if (pwmCounter > pwm[pwmOutput]) {
				HAL_GPIO_WritePin(pwmPinOutBank[pwmOutput], pwmPinOut[pwmOutput], 0);
			} else {
				HAL_GPIO_WritePin(pwmPinOutBank[pwmOutput], pwmPinOut[pwmOutput], 1);
			}
		}
	}

	if (htim->Instance == TIM3){
//TODO CREATE RAMP UP FUNCTION
	}

	if (htim->Instance == TIM6){
		speed1 = ( ((float)encoderA1 * 1000.0) / (PULSES_PER_REVOLUTION) * GEAR_REDUCTION ); // [rev/s]
		encoderA1 = 0;
	}
}
