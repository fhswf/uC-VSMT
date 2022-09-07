/*
 * main_k1_0130.c
 *
 *  Code-Beispiele zum Lehrbrief
 *  "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Stand: WS 2022/23
 *
 *
 */


#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t i = 1;   // 0x00000001

    if (*((uint8_t *)&i) == 1)
	{
		printf("little endian\r\n");  // 0x01 0x00 0x00 0x00
	}
	else
	{
		printf("big endian\r\n");	  // 0x00 0x00 0x00 0x01
	}
	return 0;
}
