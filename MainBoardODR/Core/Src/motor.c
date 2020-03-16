/*
 * motor.c
 *
 *  Created on: 2 Mar 2020
 *      Author: Madita
 */

#include "main.h"
#include "motor.h"

void moveRobot(float rotation, float x, float y) {
	float motor1 = 1 / wheelDiameter * ((-wheelCenterDistance * rotation) + x);
	float motor2 = 1 / wheelDiameter * ((-wheelCenterDistance * rotation) + (x * (-1 / 2)) + (y * -sin(M_PI / 3)));
	float motor3 = 1 / wheelDiameter * ((-wheelCenterDistance * rotation) + (x * (-1 / 2)) + (y * sin(M_PI / 3)));

	if (motor1 < 0.0) {
		pwm[1] = 0;
		pwm[0] = (uint8_t) (motor1 * 50);
	} else {
		pwm[0] = 0;
		pwm[1] = (uint8_t) (motor1 * 50);
	}

	if (motor2 < 0.0) {
		pwm[3] = 0;
		pwm[2] = (uint8_t) (motor1 * 50);
	} else {
		pwm[2] = 0;
		pwm[3] = (uint8_t) (motor1 * 50);
	}

	if (motor3 < 0.0) {
		pwm[5] = 0;
		pwm[4] = (uint8_t) (motor1 * 50);
	} else {
		pwm[4] = 0;
		pwm[5] = (uint8_t) (motor1 * 50);
	}
}
