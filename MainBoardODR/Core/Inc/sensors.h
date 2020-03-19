/*
 * sensors.h
 *
 *  Created on: 4 Mar 2020
 *      Author: Madita
 */

#ifndef INC_SENSORS_H_
#define INC_SENSORS_H_

#define AMOUNT_OF_SENSORS 9

ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc2;

void initSensors();
void MX_ADC1_Init(void);
void MX_ADC2_Init(void);
void sensorReadValue(ADC_HandleTypeDef* hadc1, ADC_HandleTypeDef* hadc2);
uint32_t sensorGetADCValue(ADC_HandleTypeDef* hadc);

#endif /* INC_SENSORS_H_ */
