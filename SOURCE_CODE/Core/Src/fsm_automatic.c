/*
 * fsm_automatic.c
 *
 *  Created on: Nov 5, 2023
 *      Author: tango
 */

#include "fsm_automatic.h"
//int flag_button_save = 0, flag_button_increase = 0, flag_button_mode = 0;
int status1 = INIT, status2 = INIT;
int counter1 = 0, counter2 = 0;
int inputLEDbuffer[4] = {0,0,0,0};

void fsm_automatic_reset(){
	setTimer(1000,3);
	HAL_GPIO_TogglePin(TOGGLE_LED_GPIO_Port, TOGGLE_LED_Pin);
	counter1 = 0, counter2 = 0;
	status1 = INIT, status2 = INIT;
	trafficDisplay1(INIT);
	trafficDisplay2(INIT);
	reset7SEG();

//	flag_button_save = 0;
//	flag_button_increase = 0;

	LED_RED_temp = LED_RED_init;
	LED_YELLOW_temp = LED_YELLOW_init;
	LED_GREEN_temp = LED_GREEN_init;
}
void fsm_automatic_run(){
	inputLEDbuffer[1] = counter1%10;
	inputLEDbuffer[0] = (counter1-inputLEDbuffer[1])/10;
	inputLEDbuffer[3] = counter2%10;
	inputLEDbuffer[2] = (counter2-inputLEDbuffer[3])/10;
	updateSEGBuffer(inputLEDbuffer);

	if(timer_flag[0] == 1) {
		setTimer(1000, 0);
		counter1--, counter2--;
	}

	switch (status1){
				case INIT:
					if(counter1<=0) {
						status1 = RED;
						counter1 = LED_RED_init;
					}
					trafficDisplay1(INIT);
					break;
				case RED:
					if(counter1<=0){
						status1 = GREEN;
						counter1 = LED_GREEN_init;
					}
					trafficDisplay1(RED);
					break;
				case GREEN:
					if(counter1<=0){
						status1 = YELLOW;
						counter1 = LED_YELLOW_init;
					}
					trafficDisplay1(GREEN);
					break;
				case YELLOW:
					if(counter1<=0){
						status1 = RED;
						counter1 = LED_RED_init;
					}
					trafficDisplay1(YELLOW);
					break;
		}
	switch (status2){
			case INIT:
				if(counter2<=0) {
					status2 = GREEN;
					counter2 = LED_GREEN_init;
				}
				trafficDisplay2(INIT);
				break;
			case RED:
				if(counter2<=0){
					status2 = GREEN;
					counter2 = LED_GREEN_init;
				}
				trafficDisplay2(RED);
				break;
			case GREEN:
				if(counter2<=0){
					status2 = YELLOW;
					counter2 = LED_YELLOW_init;
				}
				trafficDisplay2(GREEN);
				break;
			case YELLOW:
				if(counter2<=0){
					status2 = RED;
					counter2 = LED_RED_init;
				}
				trafficDisplay2(YELLOW);
				break;
	}
}


void fsm_manual(){
	int ledMatrix_in[4] = {0, TRAFFIC_MODE, 0, 0};
	switch(TRAFFIC_MODE){
		case 1:
			fsm_automatic_run();
		break;
		case 2:
			trafficToggle(RED);
			ledMatrix_in[3] = LED_RED_temp%10;
			ledMatrix_in[2] = (LED_RED_temp-ledMatrix_in[3])/10;
			updateSEGBuffer(ledMatrix_in);

		break;
		case 3:
			trafficToggle(YELLOW);
			ledMatrix_in[3] = LED_YELLOW_temp%10;
			ledMatrix_in[2] = (LED_YELLOW_temp-ledMatrix_in[3])/10;
			updateSEGBuffer(ledMatrix_in);

		break;
		case 4:
			trafficToggle(GREEN);
			ledMatrix_in[3] = LED_GREEN_temp%10;
			ledMatrix_in[2] = (LED_GREEN_temp-ledMatrix_in[3])/10;
			updateSEGBuffer(ledMatrix_in);
		break;
	}
}
