/*
 * sensors.c
 *
 *  Created on: 4 Mar 2020
 *      Author: Madita
 */
#include "main.h"
#include "sensors.h"

uint16_t sensorValues[AMOUNT_OF_SENSORS] = { 0 };
uint16_t convertedSensorValues[AMOUNT_OF_SENSORS] = { 0 };

static uint16_t sensorToCMValues[AMOUNT_OF_SENSOR_POINTS] = { 3829, 3774, 3720,
		3667, 3615, 3563, 3513, 3463, 3414, 3365, 3318, 3271, 3226, 3180, 3136,
		3093, 3050, 3008, 2966, 2925, 2885, 2846, 2807, 2769, 2732, 2695, 2659,
		2624, 2589, 2554, 2521, 2488, 2455, 2423, 2392, 2361, 2331, 2301, 2272,
		2243, 2215, 2188, 2161, 2134, 2108, 2082, 2057, 2032, 2008, 1984, 1960,
		1937, 1915, 1893, 1871, 1850, 1829, 1808, 1788, 1768, 1749, 1730, 1711,
		1692, 1674, 1657, 1639, 1622, 1606, 1589, 1573, 1557, 1542, 1527, 1512,
		1497, 1483, 1469, 1455, 1441, 1428, 1415, 1402, 1390, 1377, 1365, 1353,
		1342, 1330, 1319, 1308, 1297, 1287, 1276, 1266, 1256, 1246, 1236, 1227,
		1218, 1208, 1199, 1191, 1182, 1173, 1165, 1157, 1149, 1141, 1133, 1125,
		1118, 1110, 1103, 1096, 1089, 1082, 1075, 1068, 1062, 1055, 1049, 1043,
		1036, 1030, 1024, 1018, 1012, 1007, 1001, 995, 990, 984, 979, 974, 968,
		963, 958, 953, 948, 943, 938, 934, 929, 924, 920, 915, 910, 906, 901,
		897, 893, 888, 884, 880, 876, 871, 867, 863, 859, 855, 851, 847, 843,
		839, 836, 832, 828, 824, 820, 817, 813, 809, 805, 802, 798, 795, 791,
		787, 784, 780, 777, 773, 770, 766, 763, 759, 756, 753, 749, 746, 742,
		739, 736, 733, 729, 726, 723, 719, 716, 713, 710, 707, 703, 700, 697,
		694, 691, 688, 685, 681, 678, 675, 672, 669, 666, 663, 660, 657, 654,
		651, 649, 646, 643, 640, 637, 634, 631, 629, 626, 623, 620, 618, 615,
		612, 610, 607, 604, 602, 599, 597, 594, 591, 589, 587, 584, 582, 579,
		577, 574, 572, 570, 567, 565, 563, 561, 559, 556, 554, 552, 550, 548,
		546, 544, 542, 540, 538, 536, 534, 532, 530, 528, 527, 525, 523, 521,
		520, 518, 516, 515, 513, 511, 510, 508, 507, 505, 504, 502, 501, 500,
		498, 497, 496, 494, 493, 492, 490, 489, 488, 487, 486, 485, 483, 482,
		481, 480, 479, 478, 477, 476, 475, 474, 473, 472, 471, 470, 469, 468,
		467, 466, 465, 464, 463, 462, 461, 459, 458, 457, 456, 455, 454, 453,
		452, 451, 450, 448, 447, 446, 445, 443, 442, 441, 439, 438, 436, 435,
		433, 432, 430, 428, 426, 424, 423, 421, 418, 416, 414, 412, 410, 407,
		405, 402, 399, 397, 394, 391, 388, 384, 381, 378, 374 };

void sensorReadValue(ADC_HandleTypeDef *hadc1, ADC_HandleTypeDef *hadc2) {

	sensorValues[AMOUNT_OF_SENSORS - 1] = sensorGetADCValue(hadc1);

	int val1 = 0, val2 = 0, val3 = 0;

	for (uint8_t muxSelect = 0; muxSelect < AMOUNT_OF_SENSORS - 1;
			muxSelect++) {
		uint8_t temp = muxSelect;
		val1 = temp &= 1;
		temp = muxSelect;
		val2 = (temp &= 2) >> 1;
		temp = muxSelect;
		val3 = (temp &= 4) >> 2;

		HAL_GPIO_WritePin(GPIOA, MUX_SELECT_1_Pin, val1);
		HAL_GPIO_WritePin(GPIOA, MUX_SELECT_2_Pin, val2);
		HAL_GPIO_WritePin(GPIOA, MUX_SELECT_3_Pin, val3);
		sensorValues[muxSelect] = sensorGetADCValue(hadc2);
		HAL_Delay(500);
	}
	sensorToCM();
}

uint32_t sensorGetADCValue(ADC_HandleTypeDef *hadc) {
	uint32_t adcValue = 0;

	HAL_ADC_Start(hadc);

	if (HAL_ADC_PollForConversion(hadc, 1000) == HAL_OK) {
		adcValue = HAL_ADC_GetValue(hadc);
	}
	return adcValue;
}

void sensorToCM() {
	for (uint8_t j = 0; j < AMOUNT_OF_SENSORS; j++) {
		for (uint16_t i = 0; i < AMOUNT_OF_SENSOR_POINTS; i++) {
			if(sensorValues[j] > sensorToCMValues[i]){
				convertedSensorValues[j] = i * MILIMETERS + STARTING_POINT;
				break;
			}
		}
	}
}
