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


	for(uint8_t muxSelect = 0; muxSelect < AMOUNT_OF_SENSORS - 1; muxSelect++){

		HAL_GPIO_WritePin(GPIOA, MUX_SELECT_1_Pin, muxSelect&=1);
		HAL_GPIO_WritePin(GPIOA, MUX_SELECT_2_Pin, (muxSelect&=2 >> 1));
		HAL_GPIO_WritePin(GPIOA, MUX_SELECT_3_Pin, (muxSelect&=4 >> 2));
		sensorValues[muxSelect] = sensorGetADCValue(hadc2);
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
