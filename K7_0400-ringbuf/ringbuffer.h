/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K7_0400-ringbuf / ringbuffer.h
 *
 *  Code-Samples Lehrbrief "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Last Update: SoSe 2023
 *//*
 * ringbuffer.c
 *
 *  Created on: 01.05.2023
 *      Author: Tobias Ellermeyer
 */
#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

#define BUFFER_OK      0
#define BUFFER_FULL    1
#define BUFFER_EMPTY  -1

int16_t rb_read();
uint8_t rb_write(char c);

uint8_t rb_empty();
uint8_t rb_full();

#endif /* RINGBUFFER_H_ */
