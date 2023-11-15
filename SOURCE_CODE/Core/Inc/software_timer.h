/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2023
 *      Author: tango
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define NO_OF_TIMER 	4
#include "global.h"
extern int timer_flag[4];

void setTimer(int duration, int T_index);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
