/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MOTOR_IN_1_1_Pin GPIO_PIN_1
#define MOTOR_IN_1_1_GPIO_Port GPIOF
#define MUX_OUT_Pin GPIO_PIN_0
#define MUX_OUT_GPIO_Port GPIOA
#define MUX_SELECT_2_Pin GPIO_PIN_1
#define MUX_SELECT_2_GPIO_Port GPIOA
#define MUX_SELECT_1_Pin GPIO_PIN_2
#define MUX_SELECT_1_GPIO_Port GPIOA
#define MUX_SELECT_3_Pin GPIO_PIN_3
#define MUX_SELECT_3_GPIO_Port GPIOA
#define SENSOR_Pin GPIO_PIN_4
#define SENSOR_GPIO_Port GPIOA
#define ENCODER_B3_Pin GPIO_PIN_5
#define ENCODER_B3_GPIO_Port GPIOA
#define ENCODER_B3_EXTI_IRQn EXTI9_5_IRQn
#define ENCODER_A2_Pin GPIO_PIN_6
#define ENCODER_A2_GPIO_Port GPIOA
#define ENCODER_A2_EXTI_IRQn EXTI9_5_IRQn
#define ENCODER_B2_Pin GPIO_PIN_7
#define ENCODER_B2_GPIO_Port GPIOA
#define ENCODER_B2_EXTI_IRQn EXTI9_5_IRQn
#define ENCODER_A1_Pin GPIO_PIN_0
#define ENCODER_A1_GPIO_Port GPIOB
#define ENCODER_A1_EXTI_IRQn EXTI0_IRQn
#define ENCODER_B1_Pin GPIO_PIN_1
#define ENCODER_B1_GPIO_Port GPIOB
#define ENCODER_B1_EXTI_IRQn EXTI1_IRQn
#define ENCODER_A3_Pin GPIO_PIN_8
#define ENCODER_A3_GPIO_Port GPIOA
#define ENCODER_A3_EXTI_IRQn EXTI9_5_IRQn
#define STATUS_Pin GPIO_PIN_9
#define STATUS_GPIO_Port GPIOA
#define MOTOR_IN_3_2_Pin GPIO_PIN_10
#define MOTOR_IN_3_2_GPIO_Port GPIOA
#define MOTOR_IN_3_1_Pin GPIO_PIN_11
#define MOTOR_IN_3_1_GPIO_Port GPIOA
#define BUMPER_Pin GPIO_PIN_12
#define BUMPER_GPIO_Port GPIOA
#define BUMPER_EXTI_IRQn EXTI15_10_IRQn
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define MOTOR_IN_1_2_Pin GPIO_PIN_15
#define MOTOR_IN_1_2_GPIO_Port GPIOA
#define MOTOR_IN_2_2_Pin GPIO_PIN_4
#define MOTOR_IN_2_2_GPIO_Port GPIOB
#define MOTOR_IN_2_1_Pin GPIO_PIN_5
#define MOTOR_IN_2_1_GPIO_Port GPIOB
#define I2C_SCL_Pin GPIO_PIN_6
#define I2C_SCL_GPIO_Port GPIOB
#define I2C_SDA_Pin GPIO_PIN_7
#define I2C_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

typedef enum { false, true } bool;
#define TIMER_PERIOD 8399

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
