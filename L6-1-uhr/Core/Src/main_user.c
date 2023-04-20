/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  L6-1-uhr / main_user.c
 *
 *  Code-Samples Lehrbrief "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Last Update: SoSe 2023
 */


#include "clock.h"
#include "main.h"
#include <stdio.h>

void main_user()
{
	uint8_t hour, min, sec;

	printf("Here we go with to clock\r\n");
	if (clock_init(11,26,00) ) 		// !=0 -> error
	{
		while(1) {printf("Clock set failed\r\n"); HAL_Delay(1);}
	}

	// Periodic output of time
	while(1)
	{
		clock_get(&hour, &min, &sec);
		printf("Es ist  %02u:%02u:%02u Uhr\r\n",hour,min,sec);
		HAL_Delay(3000);
	}
}
