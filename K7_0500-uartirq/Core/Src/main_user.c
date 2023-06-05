/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K6_0500-uartirq / main_user.c
 *
 *  Code-Samples Lehrbrief "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Last Update: SoSe 2023
 */

#include "main.h"
#include "uart.h"
#include <stdio.h>

#define HAL_UART_TIMEOUT 1000


void main_user()
{
	uint16_t i=0;
	char buf[100];
	uint8_t c;

	uart_init();

	printf("*****************************\r\n");
	printf("*** UART with IRQ testing ***\r\n");
	printf("*****************************\r\n\n");


	while(1)
	{
		printf("Type some text even while sleeping...\r\n");
		printf("Sleeping for 5sec\r\n");
		HAL_Delay(5000);
		printf("Awake... Continue typing; finish with ENTER\r\n");
		printf("You typed: >");
		fflush(stdout);  // Force output on terminal w/o newline
		do
		{
			c=uart_ser_getc();
			if (c!=UART_EMPTY)
			{
				//printf("Got %c (%i)\r\n",c,c);
				uart_ser_putc(c);   // Echo received char
				buf[i++]=c;
				buf[i+1]='\0';  // Keep String-End
				if (i>98) i=98;
			}
		}
		while(c!=13);
		buf[i-1]=0;  // Remove Newline...
		printf("\r\nString received: '%s'\r\n\n",buf);
		i=0;
	}

}


