/*
 * global.c
 *
 *  Created on: Nov 5, 2023
 *      Author: tango
 */

#include "global.h"

int LED_RED_init = 5, LED_YELLOW_init = 2, LED_GREEN_init = 3;
int LED_RED_temp = 0, LED_YELLOW_temp = 0, LED_GREEN_temp = 0;
int TRAFFIC_MODE = 1;

void InitTimerSet()
{
	setTimer(2000,0);
	setTimer(1000,1);
	setTimer(1000,2);
	setTimer(1000,3);
}
