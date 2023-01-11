/*
 * main_user.c
 *
 *  Created on: Dec 20, 2022
 *      Author: Tobias Ellermeyer
 */

#include "main.h"

#define DEBOUNCE_MS  1



void main_user()
{
	uint8_t btn_state = 0x0F;  // Init with 0x0F, because default state is high

	while(1)
	{
		btn_state = btn_state << 1;       // shift left one bit position
		btn_state = btn_state | HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
		btn_state = btn_state & 0x0f;     // limit to 4 bits
		HAL_Delay(DEBOUNCE_MS);		// 5 ms delay

		if (btn_state == 0b0111)
			{
			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
			}
	}
}
