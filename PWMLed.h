/*
 * PWMLed.h
 *
 *  Created on: 07.11.2023
 *      Author: tb171606
 */

#ifndef PWMLED_H_
#define PWMLED_H_

#include "Led.h"

#define ATTRIBUTE_PWMLed() \
	int value;

#define METHODS_PWMLed() \
	int (*getValue)(PWMLed PWMled);\
	void (*setValue)(PWMLed PWMled , int value_pwm);





BEG_DEFINE_CLASS(PWMLed) EXTENDS(Led)
	METHODS_PWMLed()
END_DEFINE_CLASS(PWMLed)

BEG_DEFINE_INSTANCE(PWMLed) INSTANCE_OF(Led)
	ATTRIBUTE_PWMLed()
END_DEFINE_INSTANCE(PWMLed)


#endif /* PWMLED_H_ */
