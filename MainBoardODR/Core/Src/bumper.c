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

// Hardware interrupt is in encoders.c
