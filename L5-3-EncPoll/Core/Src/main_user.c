/*
 * main_user.c
 *
 *  Created on: 09.12.2020
 *      Author: Tobias Ellermeyer
 *
 *      Encoder Polling (not fully testet)
 *      Nucleo-STM32F103RB-Board with shield
 *
 */

#include "main.h"	// Include HAL and GPIO defines

// Handle for Timer4; defined in main.c
extern TIM_HandleTypeDef htim4;


void main_user()
{

	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);

	uint16_t enc, enc_old;
	uint16_t expand=0;
	uint32_t result=0;

	// Get initial value
	enc_old = __HAL_TIM_GET_COUNTER(&htim4);
	while(1)
	{
		enc = __HAL_TIM_GET_COUNTER(&htim4);

		// Overflow
		if ((enc < 16384) && (enc_old> 49152))	{
			expand += 1;		// += 0x00010000
		}
		// Underflow
		if ((enc > 49152) && (enc_old> 16384))	{
			expand -= 1;		// -= 0x00010000
		}
		enc_old = enc;	// Store old result
		// Final result in "result"
		result = (uint32_t)(expand<<16) | enc;
	}
}
