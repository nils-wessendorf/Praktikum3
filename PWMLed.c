/*
 * PWMLed.c
 *
 *  Created on: 07.11.2023
 *      Author: tb171606
 */


#include <stdbool.h>
#include "PWMLed.h"

static void on(PWMLed pwmled){
	led->status = 1;
	pwmWrite(pwmled->pin, 1023) ;
}

static void off(PWMLed pwmled){
	led->status = 0;
	pwmWrite(pwmled->pin, 0) ;
}


static bool getStatus(PWMLed pwmled){
	return pwmled->status;
}

static void setValue(PWMLed pwmled, int value){
    pwmWrite(pwmled->pin, value);
    pwmled->value = value;
}

static int getValue(PWMLed pwmled){
    return pwmled->value;
}



static PWMLedClass pwmledclass = {on, off, getStatus, getValue, setValue};

// Konstruktor
PWMLed newPWMLed(int* args) {

	PWMLed pwmled = malloc(sizeof(PWMLed));

	pinMode (args[0],PWM_OUTPUT);
    pwmWrite(args[0], 1023);
    led->class = &pwmledclass;
    pwmled->pin = args[0];
    pwmled->class = &pwmledclass;
    pwmled->value = 1023;
    pwmled->status = 1;
	return pwmled;
}