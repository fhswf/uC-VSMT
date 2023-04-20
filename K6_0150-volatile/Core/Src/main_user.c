/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K6_0150-volatile / main_user.c
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
#include <stdio.h>

extern uint16_t cnt;

void main_user()
{
	uint16_t cnt_old=0;

	// Start Interrupt
	irq_init();

	printf("Waiting for change of cnt\r\n");

	while(1)
	{
		// Wait until cnt gets updated
		while(cnt == cnt_old) {}

		cnt_old = cnt;	// Remember last cnt value
		printf("cnt = %u\r\n",cnt);
	}
}
