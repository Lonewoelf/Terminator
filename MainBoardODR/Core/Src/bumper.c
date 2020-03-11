/*
 * Bumper.c
 *
 *  Created on: Mar 11, 2020
 *      Author: Madita
 */
#include "bumper.h"
#include "main.h"

BUMPER_STATUS getBumperStatus(){
	if(HAL_GPIO_ReadPin(GPIOA, BUMPER_Pin) == GPIO_PIN_SET){
		return BUMPER_OK;
	}
	return BUMPER_ERROR;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);

}
