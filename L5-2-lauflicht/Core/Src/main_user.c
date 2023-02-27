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

	// wait for timer overflow
	// we use 6000, since we then have enough
	// time to modify CCR settings
	// which must be completed before next overflow

	for (of_cnt=0;of_cnt<8;of_cnt++)	// 8 overflows due to toggle on/off
	{
		while(__HAL_TIM_GetCounter(&htim3) != 6000) {};
		// Wait until timer advanced, otherwise CNT will be still 600 on next for loop
		// sind timer runs slowly
		while(__HAL_TIM_GetCounter(&htim3) != 6001) {};
	}

	// Switch CH4 and CH2 to change direction
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1);
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_4, 4000);

	while(1)
	{
		// Do nothing ...
	}
}
