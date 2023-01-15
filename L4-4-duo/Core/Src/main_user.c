/*
 * main_user.c
 *
 *  Created on: Dec 20, 2022
 *      Author: Tobias Ellermeyer
 */

#include "main.h"
#include "duoled.h"

void main_user()
{
	while(1)
	{
		led_red();
		HAL_Delay(500);
		led_green();
		HAL_Delay(500);
		led_off();
		HAL_Delay(500);
		led_orange(500);
	}
}


