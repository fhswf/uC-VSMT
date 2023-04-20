/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  L6-1-uhr-struct / clock.c
 *
 *  Code-Samples Lehrbrief "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Last Update: SoSe 2023
 */

#include "main.h"
#include "clock.h"

// Handle for Timer 3, defined in main.c
extern TIM_HandleTypeDef htim3;

// static -> local to module
// volatile -> may be changed outside normal flow
volatile static mclock_t time_m;

uint8_t clock_init(mclock_t tm)
{
	// Check range
	if ((tm.hour>23) || (tm.min>59) || (tm.sec>59))
	{
		return 1;  // Error
	}
	time_m = tm;
	// Start Time Base of Timer 3
	HAL_TIM_Base_Start_IT(&htim3);
	return 0; // no error
}

// Get current time
void clock_get(mclock_t *tm)
{
	(*tm) = time_m;
}


// ISR
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim3)	// Check if it is "our" timer
    {
    	time_m.sec++;
    	if (time_m.sec>59)
    	{
    		time_m.sec = 0;
    		time_m.min++;
    		if (time_m.min>59)
    		{
    			time_m.min = 0;
    			time_m.hour = (time_m.hour+1)%24;		// no further action required -> Use modulo to constrain
    		}
    	}
    }
}

