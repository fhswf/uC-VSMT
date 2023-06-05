/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K7_0200-uart / main_user.c
 *
 *  Code-Samples Lehrbrief "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Last Update: SoSe 2023
 */

#include "main.h"
#define HAL_UART_TIMEOUT 1000

extern UART_HandleTypeDef huart2;

void main_user()
{
	HAL_StatusTypeDef status;
	char rx_buf[10];


	status = HAL_UART_Receive(&huart2, (uint8_t*)rx_buf, 4, HAL_UART_TIMEOUT);

	if (status != HAL_OK)
	{
		// Error handling ...
	}
}


uint8_t receive_str(char * buf, int16_t buf_size, char term_char)
{
	uint16_t i=0;
	HAL_StatusTypeDef status;
	uint8_t recv;

	do
	{
		status = HAL_UART_Receive(&huart2, (uint8_t*)recv, 1, HAL_UART_TIMEOUT);
		if (recv==term_char) break;	// do not put Termination char in buf
		buf[i++]=recv;
	}
	while ((i< (buf_size-1)) && (status == HAL_OK));	// Check if buffer full or Timeout
	buf[i]='\0';  // Ensure String end
	return status;
}
