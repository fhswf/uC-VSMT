/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K7_0400-ringbuf / ringbuffer.c
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

#include <stdint.h>
#include "ringbuffer.h"

#define BUFFERSIZE 8

static uint8_t ringbuffer[BUFFERSIZE];
static uint16_t wp=0, rp=0;
static uint8_t buffer_full = 0;

uint8_t rb_write(char c)
{
	uint16_t wpx;

	if (buffer_full)
	{
		return BUFFER_FULL;
	}

	// for checking if buffer is full
	wpx = (wp+1)%BUFFERSIZE;
	if (wpx == rp)
	{
		buffer_full = 1;
		return BUFFER_FULL;
	}
	else
	{
		ringbuffer[wp]=c;
		wp = wpx;		// advance
		return BUFFER_OK;
	}

}

uint8_t rb_full()
{
	return buffer_full;
}


int16_t rb_read()
{
	int16_t c;
	if (rp == wp)
	{
		c = BUFFER_EMPTY;
	}
	else
	{
		c = ringbuffer[rp];
		rp = (rp+1) % BUFFERSIZE;
		buffer_full = 0;
	}
	return c;
}

uint8_t rb_empty()
{
	return (rp == wp);
}
