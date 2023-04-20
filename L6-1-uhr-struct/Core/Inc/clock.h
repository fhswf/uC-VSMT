/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  L6-1-uhr-struct / clock.h
 *
 *  Code-Samples Lehrbrief "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Last Update: SoSe 2023
 */

#ifndef INC_CLOCK_H_
#define INC_CLOCK_H_

#include <stdint.h>

typedef struct
{
	uint8_t hour;
	uint8_t min;
	uint8_t sec;
} mclock_t ;			// There is already a clock_t type in C -> use mclock_t

uint8_t clock_init(mclock_t tm);
void clock_get(mclock_t *tm);

#endif /* INC_CLOCK_H_ */
