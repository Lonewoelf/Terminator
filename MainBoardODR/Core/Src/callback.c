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

uint8_t acceleration = 100; //1-255 (1 highest acceleration, 255 lowest)
uint8_t counter = 0;

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
		counter++;

		if (counter >= acceleration){
			counter = 0;

			if ((uint8_t)V1Target > V1Current){
				V1Current++;
			}
			else{
				V1Current--;
			}

			if ((uint8_t)V2Target > V2Current){
				V1Current++;
			}
			else{
				V2Current--;
			}

			if ((uint8_t)V3Target > V3Current){
				V3Current++;
			}
			else{
				V3Current--;
			}

			if (V1Current < 0) {
				pwm[1] = 0;
				pwm[0] = V1Current;
			} else {
				pwm[0] = 0;
				pwm[1] = V1Current;
			}

			if (V2Current < 0) {
				pwm[3] = 0;
				pwm[2] = V2Current;
			} else {
				pwm[2] = 0;
				pwm[3] = V2Current;
			}

			if (V3Current < 0) {
				pwm[5] = 0;
				pwm[4] = V3Current;
			} else {
				pwm[4] = 0;
				pwm[5] = V3Current;
			}
		}
	}

	if (htim->Instance == TIM6){
		speed1 = ((float)encoderA1 * (float)(TIM6_BASEFREQ/TIM6_PERIOD)) / (PULSES_PER_REVOLUTION * GEAR_REDUCTION); // avaragePulse [rev/s]
		encoderA1 = 0;
	}
}

