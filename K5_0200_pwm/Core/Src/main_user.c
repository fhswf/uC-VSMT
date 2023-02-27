/*
 * main_user.c
 *
 *  Created on: 09.12.2020
 *      Author: Tobias Ellermeyer
 *
 *      TimerPWM-Fade
 *      Nucleo-STM32F103RB-Board with shield
 *
 *      LED2 -> TIM3_CH1
 */

#include "main.h"	// Include HAL and GPIO defines

// Handle for Timer3; defined in main.c
extern TIM_HandleTypeDef htim3;


void main_user()
{
	uint16_t i;

	// Start PWM-Mode in Timer 3 / Channel 1
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);

	// Infinite loop
	while(1)
	{
		// Fade 0->100% in 10% steps
		for(i=0;i<=100;i+=10)
		{
		   __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,i);
		   HAL_Delay(100);
		}
		// Fade 100->0% in 1% steps
		for(i=0;i<=100;i++)
		{
		   __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,100-i);
		   HAL_Delay(10);
		}
	}
}
