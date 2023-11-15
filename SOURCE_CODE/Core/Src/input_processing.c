/*
 * input_processing.c
 *
 *  Created on: Nov 5, 2023
 *      Author: tango
 */

#include "input_processing.h"
#define N0_OF_BUTTONS 	3
enum ButtonState { BUTTON_RELEASED , BUTTON_PRESSED ,
BUTTON_PRESSED_MORE_THAN_1_SECOND };



enum ButtonState buttonState[N0_OF_BUTTONS] = {BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED} ;

void fsm_for_input_processing ( void ){
	for(int i = 0; i< N0_OF_BUTTONS; i++){
		switch ( buttonState[i] ){
			case BUTTON_RELEASED :
				if( is_button_pressed (i)){
					buttonState[i] = BUTTON_PRESSED ;
					// INCREASE VALUE OF PORT A BY ONE UNIT
					switch (i){
					case 0: fsm_automatic_reset();
							TRAFFIC_MODE++;
							if(TRAFFIC_MODE > 4) TRAFFIC_MODE = 1;
					break;
					case 1: switch(TRAFFIC_MODE){
							case 2: LED_RED_temp++;
								break;
							case 3: LED_YELLOW_temp++;
								break;
							case 4: LED_GREEN_temp++;
								break;
							}
					break;
					case 2:
						LED_RED_init = LED_RED_temp;
						LED_YELLOW_init = LED_YELLOW_temp;
						LED_GREEN_init = LED_GREEN_temp;
						TRAFFIC_MODE++;
						if(TRAFFIC_MODE > 4) TRAFFIC_MODE = 1;
						fsm_automatic_reset();
					break;
					}
				}
			break ;
			case BUTTON_PRESSED :
				if (! is_button_pressed (i)){
					buttonState[i] = BUTTON_RELEASED ;
					//TODO1

				} else {
					if( is_button_pressed_1s (i) ){
						buttonState[i] = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
					}
				}
			break ;
			case BUTTON_PRESSED_MORE_THAN_1_SECOND :
				if (! is_button_pressed (i)){
					buttonState[i] = BUTTON_RELEASED ;
				}
			break ;
		}
	}
	fsm_manual();
}
