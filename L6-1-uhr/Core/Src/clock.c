/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  L6-1-uhr / clock.c
 *
 *  Code-Samples Lehrbrief "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Last Update: SoSe 2023
 */

#include "main.h"

// Handle for Timer 3, defined in main.c
extern TIM_HandleTypeDef htim3;

// static -> local to module
// volatile -> may be changed outside normal flow
volatile static uint8_t hour_m;
volatile static uint8_t min_m;
volatile static uint8_t sec_m;

uint8_t clock_init(uint8_t h, uint8_t m, uint8_t s)
{
	// Check range
	if ((h>23) || (m>59) || (s>59))
	{
		return 1;  // Error
	}
	hour_m = h;
	min_m = m;
	sec_m = s;
	// Start Time Base of Timer 3
	HAL_TIM_Base_Start_IT(&htim3);
	return 0; // no error
}

// Get current time
void clock_get(uint8_t *h, uint8_t *m, uint8_t *s)
{
	(*h)=hour_m;
	(*m)=min_m;
	(*s)=sec_m;
}


// ISR
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim3)	// Check if it is "our" timer
    {
    	sec_m++;
    	if (sec_m>59)
    	{
    		sec_m = 0;
    		min_m++;
    		if (min_m>59)
    		{
    			min_m = 0;
    			hour_m = (hour_m+1)%24;		// no further action required -> Use modulo to constrain
    		}
    	}
    }
}

