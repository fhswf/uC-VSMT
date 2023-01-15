/*
 * duoled.c
 *
 *  Created on: Jan 15, 2023
 *      Author: Tobias Ellermeyer
 */

#include "main.h"
#include "duoled.h"



void led_red()
{
	HAL_GPIO_WritePin(DUO1_GPIO_Port, DUO1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DUO1_GPIO_Port, DUO1_Pin, GPIO_PIN_SET);
}

void led_green()
{
	HAL_GPIO_WritePin(DUO1_GPIO_Port, DUO1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(DUO1_GPIO_Port, DUO1_Pin, GPIO_PIN_RESET);
}

void led_off()
{
	HAL_GPIO_WritePin(DUO1_GPIO_Port, DUO1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DUO1_GPIO_Port, DUO1_Pin, GPIO_PIN_RESET);
}

/*********************************************************
 * Since orange is blocking, we also set the time how long
 * orange should be displayed.
 *
 * For a non-blocking example see Timers-Chapter
 *********************************************************/
void led_orange(uint16_t time_ms)
{
	uint16_t i;

	for (i=0;i<time_ms/2;i++)
	{
		led_red();
		HAL_Delay(1);
		led_green();
		HAL_Delay(1);
	}
}

