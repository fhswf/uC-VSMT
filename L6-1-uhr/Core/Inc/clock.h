/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  L6-1-uhr / clock.h
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

uint8_t clock_init(uint8_t h, uint8_t m, uint8_t s);
void clock_get(uint8_t *h, uint8_t *m, uint8_t *s);

#endif /* INC_CLOCK_H_ */
