/*
 * sensors.c
 *
 *  Created on: 4 Mar 2020
 *      Author: Madita
 */
#include "main.h"
#include "sensors.h"

uint16_t sensorValues[AMOUNT_OF_SENSORS] = {0};

void sensorReadValue(ADC_HandleTypeDef* hadc1, ADC_HandleTypeDef* hadc2){

	sensorValues[AMOUNT_OF_SENSORS - 1] = sensorGetADCValue(hadc1);

	int val1 = 0, val2 = 0, val3 = 0;

	for(uint8_t muxSelect = 0; muxSelect < AMOUNT_OF_SENSORS - 1; muxSelect++){
		uint8_t temp = muxSelect;
		val1 = temp&=1;
		temp = muxSelect;
		val2 = (temp&=2)>>1;
		temp = muxSelect;
		val3 = (temp&=4)>>2;

		HAL_GPIO_WritePin(GPIOA, MUX_SELECT_1_Pin, val1);
		HAL_GPIO_WritePin(GPIOA, MUX_SELECT_2_Pin, val2);
		HAL_GPIO_WritePin(GPIOA, MUX_SELECT_3_Pin, val3);
		sensorValues[muxSelect] = sensorGetADCValue(hadc2);
		//HAL_Delay(500);
	}
}

uint32_t sensorGetADCValue(ADC_HandleTypeDef* hadc){
	uint32_t adcValue = 0;

	HAL_ADC_Start(hadc);

	if(HAL_ADC_PollForConversion(hadc, 1000) == HAL_OK){
		adcValue = HAL_ADC_GetValue(hadc);
	}
	return adcValue;
}
