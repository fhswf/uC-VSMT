/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  L7-2-temp / main_user.c
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

#define LM75B_1 (0x48<<1)


void main_user()
{
	HAL_StatusTypeDef status;
	uint8_t buf[2];
	uint8_t cnt = 0;
	uint8_t simvals[]={0x7f, 0x00,  // 0111 1111 000	= 125 degC
			           0x19, 0x00, 	// 0001 1001 000    =  25 degC
			           0x00, 0x00, 	// 0000 0000 000	=   0 degC
			           0xE7, 0x00 	// 1110 0111 000    = -25 degC
	           };

	int16_t ival;
	float celsius;

	uart_init();   // IRQ-UART aus K7-0500

	status = HAL_I2C_IsDeviceReady(&hi2c1, (LM75B_1 <<1), 1, 10);

	if (status != HAL_OK)
	{
		printf("Simulation, no real LM75B found\r\n");
	}
	while (1)
	{
		if (status != HAL_OK)  //simulation
		{
			printf("SIM [%i] ",cnt);
			buf[0]=simvals[cnt*2];
			buf[1]=simvals[cnt*2+1];
			cnt = (cnt+1)%4;
		} else
		{
			if (HAL_I2C_Mem_Read(&hi2c1, LM75B_1, 0x00, I2C_MEMADD_SIZE_8BIT, buf, 2, 100)!=HAL_OK)
			{
				printf("Error reading from Device\r\n");
			}
		}

		ival = buf[0] << 8 | buf[1];

		celsius = (float)ival*127.0 / 0x7f00;  // 0b0111 1111 000 = 127.0 degC, see data sheet

		printf("buf[0]=0x%02X buf[1]=0x%02X ival=%6i  celsius=%6.3f\r\n",
				buf[0],buf[1],ival,celsius);
		HAL_Delay(500);
	}
}


