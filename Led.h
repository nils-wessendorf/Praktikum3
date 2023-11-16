/*
 * led.h
 *
 *  Created on: 07.11.2023
 *      Author: tb171606
 */

#ifndef LED_H_
#define LED_H_

#include "makro.h"
#include <stdio.h>
#include <stdbool.h>
#include <wiringPi.h>

#define METHODS_Led() \
	void (*on)(Led led);\
	void (*off)(Led led);\
	bool (*getStatus)(Led led);

#define ATTRIBUTE_Led() \
	bool status;\
	int pin;

BEG_DEFINE_CLASS(Led)
	METHODS_Led()
END_DEFINE_CLASS(Led)

BEG_DEFINE_INSTANCE(Led)
	ATTRIBUTE_Led()
END_DEFINE_INSTANCE(Led)


//test

#endif /* LED_H_ */
