/*
 * main_user.c
 *
 *  Created on: Dec 20, 2022
 *      Author: Tobias Ellermeyer
 */

#include "main.h"
/*********************************
 * Uses printf via USB serial ...
 * Only TX, see usb_printf.c
 *********************************/
#include <stdio.h>

#define DEBOUNCE_MS  1

#define BUTTON_NOT_PRESSED 0
#define BUTTON_PRESSED     1
#define BUTTON_DOWN		   2
#define BUTTON_UP		   3

/************************************
 * More complex example, show how to
 * implement button in function with
 * static variables
 ************************************/
uint8_t button_pressed();


void main_user()
{
	uint8_t btn;

	printf("Here we go... Press the blue button\r\n");
	while(1)
	{
		HAL_Delay(DEBOUNCE_MS);		// 5 ms delay
		btn = button_pressed();
		switch(btn)
		{
		case BUTTON_DOWN:
			printf("Button just pressed\r\n");
			break;
		case BUTTON_UP:
			printf("Button just released\r\n");
			break;
		default: break;
		}
	}
}


uint8_t button_pressed()
{
   static uint8_t btn_state = 0x0F;  // Init with 0x0F, because default state is high

   uint8_t ret = BUTTON_NOT_PRESSED;

   btn_state = btn_state << 1;       // shift left one bit position
   btn_state = btn_state | HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
   btn_state = btn_state & 0x0f;     // limit to 4 bits


   switch(btn_state)
   {
	  case 0b1000: // button just pressed (single event)
				   //printf("Button just pressed\r\n");
		  	       ret = BUTTON_DOWN;
		  	  	   break;
	  case 0b0000: // button still pressed
		  	  	   ret = BUTTON_PRESSED;
				   break;
	  case 0b0111: // button just released (single event)
				   //printf("Button just released\r\n");
		  	  	   ret = BUTTON_UP;
				   break;
	  case 0b1111: // button still released
				   break;
	  default:     break;
	}
	return(ret);
}
