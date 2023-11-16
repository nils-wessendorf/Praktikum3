/*
 * blink.c:
 *	Standard "blink" program in wiringPi. Blinks an LED connected
 *	to the first GPIO pin.
 *
 * Copyright (c) 2012-2013 Gordon Henderson.
 ***********************************************************************
 * This file is part of wiringPi:
 *      https://github.com/WiringPi/WiringPi
 *
 *    wiringPi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    wiringPi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with wiringPi.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

#include <stdio.h>
#include <wiringPi.h>
#include "Led.h"
#include "PWMLed.h"

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
// LED Pin - wiringPi pin 26 is BCM_GPIO 12 mit PWM-Fähigkeit.
#define	LED1	0
#define PWMLED2  26

int main (void)
{
  printf ("Raspberry Pi blink\n") ;

  wiringPiSetup () ;
  

  Led led1 = newLed(LED1);
  led1->class->on(led1);
  
  PWMLed pwmled1 = newPWMLed(PWMLED2);
  pwmled1->class->setValue(pwmled1, 500);

  return 0;
}
