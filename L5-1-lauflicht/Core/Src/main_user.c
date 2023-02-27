/*
 * main_user.c
 *
 *  Created on: 09.12.2020
 *      Author: Tobias Ellermeyer
 *
 *      TimerBlink
 *      Nucleo-STM32F103RB-Board with shield
 *
 *      LED2 -> TIM3_CH1
 *      LED3 -> TIM3_CH2
 */

#include "main.h"	// Include HAL and GPIO defines

// Handle for Timer3; defined in main.c
extern TIM_HandleTypeDef htim3;


void main_user()
{

	uint8_t of_cnt;	// to count timer overflows

	// Start OC-Mode in Timer 3 / Channel 1 & 2
	HAL_TIM_OC_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_OC_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_OC_Start(&htim3, TIM_CHANNEL_4);

	while(1)
	{
		// Do nothing ...
	}
}
