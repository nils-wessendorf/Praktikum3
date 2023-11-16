/*
 * Led.c
 *
 *  Created on: 07.11.2023
 *      Author: tb171606
 */


#include "Led.h"
#include<stdlib.h>





static void on(Led led){
	led->status = 1;
	digitalWrite (led->pin, HIGH) ;
}

static void off(Led led){
	led->status = 0;
	digitalWrite (led->pin, LOW) ;
}

static bool getStatus(Led led){
	return led->status;
}

static LedClass ledclass = {on, off, getStatus};

// Konstruktor
Led newLed(int* args) {

	Led led = malloc(sizeof(Led));
	
	pinMode (args[0], OUTPUT) ;
    led->class = &ledclass;
	led->pin = args[0];
	led->status = 0;

	
	return led;
}
