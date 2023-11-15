/*
 * display7SEG.c
 *
 *  Created on: Nov 5, 2023
 *      Author: tango
 */

#include "display.h"

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {0, 0, 0, 0};

void Led_Status(int LedArray[7]){
	  HAL_GPIO_WritePin ( SEG0_GPIO_Port, SEG0_Pin , LedArray[0]);
	  HAL_GPIO_WritePin ( SEG1_GPIO_Port, SEG1_Pin , LedArray[1]);
	  HAL_GPIO_WritePin ( SEG2_GPIO_Port, SEG2_Pin , LedArray[2]);
	  HAL_GPIO_WritePin ( SEG3_GPIO_Port, SEG3_Pin , LedArray[3]);
	  HAL_GPIO_WritePin ( SEG4_GPIO_Port, SEG4_Pin , LedArray[4]);
	  HAL_GPIO_WritePin ( SEG5_GPIO_Port, SEG5_Pin , LedArray[5]);
	  HAL_GPIO_WritePin ( SEG6_GPIO_Port, SEG6_Pin , LedArray[6]);
}

void display7SEG(int num){
	switch(num){
		case 0: {
					int LedArray[7] = { 0, 0, 0, 0, 0, 0, 1};
					Led_Status(LedArray);
				}
		break;

		case 1: {
					int LedArray[7] = { 1, 0, 0, 1, 1, 1, 1};
					Led_Status(LedArray);
				}
				break;
		case 2: {
					int LedArray[7] = { 0, 0, 1, 0, 0, 1, 0};
					Led_Status(LedArray);
				}
				break;
		case 3: {
					int LedArray[7] = { 0, 0, 0, 0, 1, 1, 0};
					Led_Status(LedArray);
				}
				break;
		case 4: {
					int LedArray[7] = { 1, 0, 0, 1, 1, 0, 0};
					Led_Status(LedArray);
				}
				break;
		case 5: {
					int LedArray[7] = { 0, 1, 0, 0, 1, 0, 0};
					Led_Status(LedArray);
				}
				break;
		case 6: {
					int LedArray[7] = { 0, 1, 0, 0, 0, 0, 0};
					Led_Status(LedArray);
				}
				break;
		case 7: {
					int LedArray[7] = { 0, 0, 0, 1, 1, 1, 1};
					Led_Status(LedArray);
				}
				break;
		case 8: {
					int LedArray[7] = { 0, 0, 0, 0, 0, 0, 0};
					Led_Status(LedArray);
				}
				break;
		case 9: {
					int LedArray[7] = { 0, 0, 0, 0, 1, 0, 0};
					Led_Status(LedArray);
				}
				break;
		default: {
					int LedArray[7] = { 0, 0, 0, 0, 0, 0, 1};
					Led_Status(LedArray);
				}
				break;
	}
}
void update7SEG( int index ){
	if(index_led >= MAX_LED) index_led = 0;
	switch ( index ){
	case 0:
		// Display the first 7 SEG with led_buffer [0]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
		display7SEG(led_buffer[0]);
		break ;
	case 1:
		// Display the second 7 SEG with led_buffer [1]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,0);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
		display7SEG(led_buffer[1]);
		break ;
	case 2:
		// Display the third 7 SEG with led_buffer [2]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,1);
		display7SEG(led_buffer[2]);
		break ;
	case 3:
		// Display the forth 7 SEG with led_buffer [3]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,0);
		display7SEG(led_buffer[3]);
		break ;
	default :
		break ;
	}
}
void updateSEGBuffer(int input[MAX_LED]){
	for(int i = 0; i<MAX_LED; i++) led_buffer[i] = input[i];
	if(timer_flag[1] == 1){
		setTimer(250, 1);
		update7SEG(index_led++);
	}
}
void reset7SEG(){
	index_led = 0;
	int ledbufferReset[4] = {0,0,0,0};
	updateSEGBuffer(ledbufferReset);
}
