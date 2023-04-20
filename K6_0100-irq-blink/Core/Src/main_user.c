/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K6_0100-irq-blink / main_user.c
 *
 *  Code-Samples Lehrbrief "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Last Update: SoSe 2023
 */


#include "main.h"
#include "irq.h"

void main_user()
{
	// Start blinking ...
	irq_blink_init();

	HAL_Delay(5000);	// Wait 5 sec

	irq_blink_speed(100);	// Set Speed

	HAL_Delay(5000);	// Wait 5 sec

	// Change pattern
	irq_blink_setpattern(0b01010000);

	while(1);	// Wait forever
}
