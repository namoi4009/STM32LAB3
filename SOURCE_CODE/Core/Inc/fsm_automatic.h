/*
 * fsm_automatic.h
 *
 *  Created on: Nov 5, 2023
 *      Author: tango
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#define INIT 			0
#define RED 			1
#define YELLOW			2
#define GREEN			3

#include "global.h"

void fsm_automatic_reset();
void fsm_automatic_run();
void fsm_manual();

#endif /* INC_FSM_AUTOMATIC_H_ */
