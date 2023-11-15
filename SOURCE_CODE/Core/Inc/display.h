/*
 * display.h
 *
 *  Created on: Nov 5, 2023
 *      Author: tango
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "global.h"
void toggleLED();
void updateSEGBuffer(int input[4]);
void reset7SEG();

void trafficDisplay1(int index);
void trafficDisplay2(int index);
void trafficToggle(int index);

#endif /* INC_DISPLAY_H_ */
