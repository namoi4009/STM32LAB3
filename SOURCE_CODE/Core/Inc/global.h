/*
 * global.h
 *
 *  Created on: Nov 5, 2023
 *      Author: tango
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

//Begin define

//End define
//Begin include
#include "input_processing.h"
#include "software_timer.h"
#include "input_reading.h"
#include "main.h"
#include "fsm_automatic.h"
#include "display.h"
//End include

//Begin extern
extern int LED_RED_init, LED_YELLOW_init, LED_GREEN_init;
extern int LED_RED_temp, LED_YELLOW_temp, LED_GREEN_temp;

extern int TRAFFIC_MODE;
//End extern

//Begin global function
void toggleLED();
void InitTimerSet();
//End global function

#endif /* INC_GLOBAL_H_ */
