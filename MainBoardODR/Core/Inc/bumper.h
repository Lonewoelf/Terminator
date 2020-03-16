/*
 * Bumper.h
 *
 *  Created on: Mar 11, 2020
 *      Author: Madita
 */

#ifndef INC_BUMPER_H_
#define INC_BUMPER_H_

typedef enum {
	BUMPER_NONE = -1,
	BUMPER_OK = 0,
	BUMPER_ERROR = 1
}BUMPER_STATUS;

BUMPER_STATUS getBumperStatus();


#endif /* INC_BUMPER_H_ */
