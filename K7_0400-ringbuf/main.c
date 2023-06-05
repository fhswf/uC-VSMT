/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K7_0400-ringbuf / main.c
 *
 *  Code-Samples Lehrbrief "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Last Update: SoSe 2023
 */

#include <stdio.h>
#include <stdint.h>
#include "ringbuffer.h"

int main()
{
	uint16_t i;
	int16_t  res;
	char bufstatus[3][5]={"-OK-","FULL","EMPT"};

	printf("*** (101,102, ... 105) Write 5 items to Ring buffer\r\n");
	for (i=1;i<=5;i++)
	{
		res = rb_write(100+i);
		printf(" (%i)=%3i %s |",i,100+i,bufstatus[res]);
	}
	printf("\r\n");

	printf("*** (101,102,103) Read 3 items from Ring buffer\r\n");
	for (i=1;i<=3;i++)
	{
		res = rb_read();
		printf(" (%i)=%3i %s |",i,res,bufstatus[ (res==-1)*2]);
	}
	printf("\r\n\n");

	printf("*** (201,202, ... 205) Write 5 items to Ring buffer\r\n");
	for (i=1;i<=5;i++)
	{
		res = rb_write(200+i);
		printf(" (%i)=%3i %s |",i,200+i,bufstatus[res]);
	}
	printf("\r\n");

	printf("*** (104,105,201, ...) Read 7 items from Ring buffer\r\n");
	for (i=1;i<=7;i++)
	{
		res = rb_read();
		printf(" (%i)=%3i %s |",i,res,bufstatus[ (res==-1)*2]);
	}
	printf("\r\n\n");

	// write 8 times to ring buffer  (square numbers 1,4,9, ... 49, (64)
	printf("*** (1,4,9, ...) Write 8 items to Ring buffer (last should give buffer full)\r\n");
	for (i=1;i<=8;i++)
	{
		res = rb_write(i*i);
		printf(" (%i)=%3i %s |",i,i*i,bufstatus[res]);
	}
	printf("\r\n");
	// read 8 times from ring buffer (square numbers 1,4,9, ... 49)
	printf("*** (1,4,9, ...) Read 8 items from Ring buffer (last should give buffer empty)\r\n");
	for (i=1;i<=8;i++)
	{
		res = rb_read();
		printf(" (%i)=%3i %s |",i,res,bufstatus[ (res==-1)*2]);
	}
	printf("\r\n\n");
}
