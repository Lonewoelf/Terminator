/*
 * motor.c
 *
 *  Created on: 2 Mar 2020
 *      Author: Madita
 */



#include "main.h"
#include "motor.h"

float V1Current = 0.0;
float V2Current = 0.0;
float V3Current = 0.0;

float V1Target = 0.0;
float V2Target = 0.0;
float V3Target = 0.0;

uint8_t pwmCounter = 0;

int8_t pwm[AMOUNT_OF_MOTOR_CHANNELS] = {20, 40, 60, 80, 90, 30};

GPIO_TypeDef* pwmPinOutBank[AMOUNT_OF_MOTOR_CHANNELS] = {GPIOB, GPIOA, GPIOB, GPIOB, GPIOA, GPIOA};

uint16_t pwmPinOut[AMOUNT_OF_MOTOR_CHANNELS] = {
		MOTOR_IN_1_1_Pin,
		MOTOR_IN_1_2_Pin,
		MOTOR_IN_2_1_Pin,
		MOTOR_IN_2_2_Pin,
		MOTOR_IN_3_1_Pin,
		MOTOR_IN_3_2_Pin};

void initMotors(){
	MX_TIM2_Init();
	HAL_TIM_Base_Start_IT(&htim2);
	MX_TIM3_Init();
	HAL_TIM_Base_Start_IT(&htim3);
}

void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 48;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 100;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 48;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 10000;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

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
}

void moveRobot(float OM, float Theta, float VxW, float VyW){
	float VxM = cos(Theta) * VxW + sin(Theta) * VyW;
	float VyM = -sin(Theta) * VxW + cos(Theta) * VyW;

	V1Target = -VxM/(2.0*WHEEL_CENTER_RADIUS) -(sqrt(3.0)*VyM)/(2.0*WHEEL_CENTER_RADIUS) + WHEEL_CENTER_RADIUS*OM;
	V2Target = VxM+WHEEL_CENTER_RADIUS*OM;
	V3Target = -VxM/(2.0*WHEEL_CENTER_RADIUS) +(sqrt(3.0)*VyM)/(2.0*WHEEL_CENTER_RADIUS) + WHEEL_CENTER_RADIUS*OM;
}

void demoMotors(){
	moveRobot(0.0, 0.0, 50.0, 0.0);
	HAL_Delay(2000);
	moveRobot(0.0, 0.0, 0.0, 50.0);
	HAL_Delay(2000);
	moveRobot(0.0, 0.0, -50.0, 0.0);
	HAL_Delay(2000);
	moveRobot(0.0, 0.0, 0.0, -50.0);
	HAL_Delay(2000);
	moveRobot(0.0, 0.0, 0.0, 0.0);
}

//void moveRobot(float rotation, float x, float y) { DEPRECATED
//	float motor1 = 1 / WHEEL_DIAMETER * ((-WHEEL_CENTER_RADIUS * rotation) + x);
//	float motor2 = 1 / WHEEL_DIAMETER * ((-WHEEL_CENTER_RADIUS * rotation) + (x * (-1 / 2)) + (y * -sin(M_PI / 3)));
//	float motor3 = 1 / WHEEL_DIAMETER * ((-WHEEL_CENTER_RADIUS * rotation) + (x * (-1 / 2)) + (y * sin(M_PI / 3)));
//
//	if (motor1 < 0.0) {
//		pwm[1] = 0;
//		pwm[0] = (uint8_t) (motor1 * 50);
//	} else {
//		pwm[0] = 0;
//		pwm[1] = (uint8_t) (motor1 * 50);
//	}
//
//	if (motor2 < 0.0) {
//		pwm[3] = 0;
//		pwm[2] = (uint8_t) (motor1 * 50);
//	} else {
//		pwm[2] = 0;
//		pwm[3] = (uint8_t) (motor1 * 50);
//	}
//
//	if (motor3 < 0.0) {
//		pwm[5] = 0;
//		pwm[4] = (uint8_t) (motor1 * 50);
//	} else {
//		pwm[4] = 0;
//		pwm[5] = (uint8_t) (motor1 * 50);
//	}
//}
