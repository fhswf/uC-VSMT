/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K6_0400-codegen / irq_pc.c
 *
 *  Code-Samples Lehrbrief "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Last Update: SoSe 2023
 */


#include "main.h"

#define DEBOUNCE_TIME 100	// 100 ms

void EXTI15_10_IRQHandler(void)
{
   static uint32_t last_toggle = 0;		// SysTick of last toggle
   uint32_t tick;

   tick = HAL_GetTick();         // Check debounce
   if ( (tick - last_toggle) > DEBOUNCE_TIME)
   {
	  last_toggle = tick;
	  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
   }
}
