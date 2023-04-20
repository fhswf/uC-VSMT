/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K6_0350-pc-db / irq_pc.c
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

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
   static uint32_t last_toggle = 0;		// SysTick of last toggle
   uint32_t tick;
   if(GPIO_Pin == GPIO_PIN_13)  // Check for Pin PC13
   {
      // Check debounce
	  tick = HAL_GetTick();
	  if ( (tick - last_toggle) > DEBOUNCE_TIME)
	  {
		  last_toggle = tick;
		  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	  }
   }
}
