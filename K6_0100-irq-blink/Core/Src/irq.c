/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K6_0100-irq-blink / irq.c
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

// Default pattern
static uint8_t pattern = 0b00101110;

void irq_blink_init()
{
	// Start Time Base of Timer 3
	HAL_TIM_Base_Start_IT(&htim3);
}

// Set New Pattern
void irq_blink_setpattern(uint8_t npat)
{
	pattern = npat;
}

// Set speed per step in milli seconds
void irq_blink_speed(uint16_t ms)
{
	__HAL_TIM_SET_AUTORELOAD(&htim3,ms*10-1);
	// or: htim3.Instance->ARR=ms*10-1;
}

// Get HAL Event
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	static uint8_t mask = 0x80;  // The blink mask
	uint8_t state;

    if (htim == &htim3)	// Check if it is "our" timer
    {
    	state = (mask & pattern) !=0;	// LED on? -> state = 1 = GPIO_PIN_SET
   		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, state);
   		mask = mask >>1;
   		if (mask==0) mask = 0x80;	    // next round
    }
}

