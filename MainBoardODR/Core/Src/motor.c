/*
 * motor.c
 *
 *  Created on: 2 Mar 2020
 *      Author: Madita
 */

#include "main.h"
#include "motor.h"

static int8_t pwm[AMOUNT_OF_MOTOR_CHANNELS] = {20, 40, 60, 80, 90, 30};

static GPIO_TypeDef* pwmPinOutBank[AMOUNT_OF_MOTOR_CHANNELS] = {GPIOB, GPIOA, GPIOB, GPIOB, GPIOA, GPIOA};

static uint16_t pwmPinOut[AMOUNT_OF_MOTOR_CHANNELS] = {
		MOTOR_IN_1_1_Pin,
		MOTOR_IN_1_2_Pin,
		MOTOR_IN_2_1_Pin,
		MOTOR_IN_2_2_Pin,
		MOTOR_IN_3_1_Pin,
		MOTOR_IN_3_2_Pin};

static uint8_t pwmCounter = 0;

uint8_t motorGetSpeed(uint8_t motorID){
	return 0;
}

bool motorBreak(){
	return true;
}

bool motorBreakFast(){
	return true;
}

bool motorSpeedUp(uint8_t factor, uint8_t motorID){
	return true;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim2) {
	if (htim2->Instance == TIM2) {
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
}
