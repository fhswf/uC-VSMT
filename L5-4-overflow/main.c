/*
 * main.c
 *
 *  Created on: 24.08.2022
 *      Author: Tobias Ellermeyer
 */


#include <stdio.h>
#include <stdint.h>

int main()
{
	uint16_t act = 21;
	uint16_t old = 65511;
	uint16_t res;

	res = act - old;

	printf("Result: %u\r\n",res);
	return 0;
}
