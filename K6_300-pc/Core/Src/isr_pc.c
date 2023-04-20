/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K6_0300-pc / irq_pc.c
 *
 *  Code-Samples Lehrbrief "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Last Update: SoSe 2023
 */


#include "main.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin == GPIO_PIN_13)  // Check for Pin PC13
  {
    /* Toggle LED LD2 */
    HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
  }
}
