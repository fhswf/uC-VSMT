/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K6_0200-irq-oc / irq.c
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

void irq_oc_init()
{
	// Start Time Base of Timer 3
	HAL_TIM_Base_Start_IT(&htim3);
	// Start Output Compare with interrupt
    HAL_TIM_OC_Start_IT(&htim3,TIM_CHANNEL_1);
}

// Get HAL Event for timer overflow
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim3)	// Check if it is "our" timer
    {
    	// LED on
   		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
    }
}

// Get HAL Event for output compare match
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim3)	// Check if it is "our" timer
    {
        if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
        {
			// LED off
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
        }
    }
}

