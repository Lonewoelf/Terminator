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
    MX_TIM1_Init();
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

	case BUMPER_Pin:
		break;

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

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 48;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 1000;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
  sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
  sBreakDeadTimeConfig.Break2Filter = 0;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}
