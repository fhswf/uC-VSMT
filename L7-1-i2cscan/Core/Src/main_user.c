/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  L7-1-i2cscan / main_user.c
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

// Handle for I2C1
extern I2C_HandleTypeDef hi2c1;


void main_user()
{
	uint8_t addr;
	HAL_StatusTypeDef status;

	uart_init();   // IRQ-UART aus K7-0500

	printf("*****************************\r\n");
	printf("*** Scanning I2C-Bus I2C1 ***\r\n");
	printf("*****************************\r\n\n");

	// 0000xxx reserved -> Start Scannung at addr 8
	// 1111xxx reserved -> Stop at 0b1110111

	printf("Addresses are 7-bit hex values!\r\n");

	printf("                        "); // for addr 0...7
	for (addr = 0b0001000; addr<0b1111000; addr++)
	{
		if ( (addr%16) == 0) printf("\r\n"); // newline every 16 entries
		// Test, 1 trial, 10 ms Timeout
		// Keep in mind that 7 bit addr needs to be shifted
		status = HAL_I2C_IsDeviceReady(&hi2c1, (addr <<1), 1, 10);
		if (status == HAL_OK)  // ACK received
		{
			printf("%02X ",addr);
		} else
		{
			printf("-- ");
		}
	}
	printf("\r\n\nDone...\r\n");
	while(1);
}


