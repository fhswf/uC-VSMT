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


	/*
	 *  TIMER CONFIGURATION FOM STM32CubeMX:
	 *
	 *  PSC=7199 / ARR = 4999
	 *
	 *
	 *
	 *
	 *  f= CK_IN / ((PSC+1)*(ARR+1)) = 72 MHz / (7200 * 5000) = 2 Hz
	 *
	 *  Mode = Toggle --> Led blinks at 1 Hz
	 *
	 */

	// Start OC-Mode in Timer 3 / Channel 1 & 2
	HAL_TIM_OC_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_OC_Start(&htim3, TIM_CHANNEL_2);
	// -> Now LEDs should blink @ 1Hz

	// Wait for 5 sec
	HAL_Delay(5000);

	// Change ARR to 9999 -> 1/2 Hz
	htim3.Instance->ARR =9999;
	// ==> Now we should observe slower blinking on both LEDs

	// Again wait 6 sec
	HAL_Delay(6000);

	// Add phase shift of 1/4 period on LED3 -> CCR2=9999/4=2500

	while(htim3.Instance->CNT < (9999/4+1) ); // Wait until timer CNT is larger than desired CCR2 value
	htim3.Instance->CCR2 = 9999/4;
	// ==> Now we should observe LED3 out of phase


	// Infinite loop
	while(1)
	{
		// Do nothing ...
	}
}
