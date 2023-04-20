/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K6_0155-volatile2 / irq.c
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

volatile uint16_t cnt;   // Counter for ISR Events

void irq_init()
{
	cnt=0;
	// Start Time Base of Timer 3
	HAL_TIM_Base_Start_IT(&htim3);
}

// ISR
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim3)	// Check if it is "our" timer
    {
    	cnt++;
    }
}

