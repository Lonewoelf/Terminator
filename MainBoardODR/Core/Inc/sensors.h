/*
 * sensors.h
 *
 *  Created on: 4 Mar 2020
 *      Author: Madita
 */

#ifndef INC_SENSORS_H_
#define INC_SENSORS_H_

#define AMOUNT_OF_SENSORS 9
#define AMOUNT_OF_SENSOR_POINTS 371
#define MILIMETERS 0.1
#define STARTING_POINT 3

ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc2;

uint16_t convertedSensorValues[AMOUNT_OF_SENSORS];

void sensorsInit();
void MX_ADC1_Init(void);
void MX_ADC2_Init(void);
void sensorReadValue(ADC_HandleTypeDef* hadc1, ADC_HandleTypeDef* hadc2);
uint32_t sensorGetADCValue(ADC_HandleTypeDef* hadc);
void sensorToCM();

#endif /* INC_SENSORS_H_ */
