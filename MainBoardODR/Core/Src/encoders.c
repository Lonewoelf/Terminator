/*
 * encoders.c
 *
 *  Created on: Mar 11, 2020
 *      Author: Madita
 */
#include "encoders.h"
#include "main.h"
#include "motor.h"

void encoderInit(){
	timerValue = 0;
	encoderA1 = 0;
	encoderA2 = 0;
	encoderA3 = 0;
	encoderB1 = 0;
	encoderB2 = 0;
	encoderB3 = 0;
	speed1 = 0;
	speed2 = 0;
	speed3 = 0;
	MX_TIM6_Init();
	HAL_TIM_Base_Start_IT(&htim6);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	timerValue = TIM1->CNT;

	switch(GPIO_Pin){

	case ENCODER_A1_Pin:
		encoderA1++;
		break;

	case ENCODER_A2_Pin:

		break;

	case ENCODER_A3_Pin:
//		temp3 = encoderA3;
//		encoderA3 = timerValue;
//		if (encoderCalculateSpeed(encoderA3, temp3) > 0){
//			speed3 = encoderCalculateSpeed(encoderA3, temp3);
//		}
		break;

	case BUMPER_Pin:
		break;

//	case ENCODER_B1_Pin:
//
//	case ENCODER_B2_Pin:
//
//	case ENCODER_B3_Pin:

	}
}

uint32_t encoderCalculateSpeed(uint32_t time, uint32_t timePrev){ // m/s
	return (time - timePrev);
}

<<<<<<< HEAD
/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
=======
void MX_TIM6_Init(void)
>>>>>>> Development
{

  /* USER CODE BEGIN TIM6_Init 0 */

  /* USER CODE END TIM6_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
<<<<<<< HEAD
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
=======

  /* USER CODE BEGIN TIM6_Init 1 */

  /* USER CODE END TIM6_Init 1 */
  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 48;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 1000;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
>>>>>>> Development
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM6_Init 2 */

  /* USER CODE END TIM6_Init 2 */

}


/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
