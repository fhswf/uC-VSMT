/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K7_0500-uartirq / uart.c
 *
 *  Code-Samples Lehrbrief "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Last Update: SoSe 2023
 */
#ifndef SRC_UART_C_
#define SRC_UART_C_

#include "main.h"
#include "uart.h"
#include <stdio.h>


static uint8_t rx_ser_buf[RXBUF_LEN];		// Receive Buffer UART1
static uint8_t tx_ser_buf[TXBUF_LEN];		// Transmit Buffer UART1
static volatile uint16_t rx_ser_i, tx_ser_o;
static uint16_t rx_ser_e, tx_ser_i;
static volatile uint8_t tx_ser_busy;
static volatile uint8_t tx_ser_cnt;


extern UART_HandleTypeDef huart2;



#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE
{
  //HAL_UART_Transmit(&huart1, (uint8_t *)&ch,1,0xffff);
  uart_ser_putc(ch);
  return ch;
}

void uart_init()
{
	tx_ser_i  = 0;
	rx_ser_i  = 0;
	rx_ser_e  = 0;

	tx_ser_busy = 0;
	tx_ser_cnt = 0;

	// Enable Interrupt for RX
	__HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);
}

void uart_ser_putc(uint8_t byte)
{
	// Wait until buffer has free space
	while (tx_ser_cnt > (TXBUF_LEN-1));

    tx_ser_buf[TXBUF_MSK & tx_ser_i] = byte;
    tx_ser_i++;
    tx_ser_cnt++;
    tx_ser_busy = 1;
    // Enable ISR for TX, since we now have chars in buf
    __HAL_UART_ENABLE_IT(&huart2, UART_IT_TXE);
}

uint8_t uart_ser_getc()
{
	uint8_t c;
	if (rx_ser_i == rx_ser_e)  // No chars received
	{
		c = UART_EMPTY;
	}
	else		// There are chars in ringbuffer
	{
		c = rx_ser_buf[RXBUF_MSK & rx_ser_e];
		rx_ser_e++;
	}
	return c;
}


//***********************************************************************
// IRQ Handler
//***********************************************************************

void USART2_IRQHandler(void)
{
    /* USER CODE BEGIN USART1_IRQn 0 */
    if((__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE) != RESET) &&
       (__HAL_UART_GET_IT_SOURCE(&huart2, UART_IT_RXNE) != RESET))
    {
        rx_ser_buf[rx_ser_i & RXBUF_MSK] = (uint8_t)(huart2.Instance->DR & 0x00FF);
        rx_ser_i++;
        /* Clear RXNE interrupt flag */
        //__HAL_UART_SEND_REQ(&huart1, UART_RXDATA_FLUSH_REQUEST);
        __HAL_UART_CLEAR_NEFLAG(&huart2);
    }
    if((__HAL_UART_GET_FLAG(&huart2, UART_FLAG_TXE) != RESET) &&
       (__HAL_UART_GET_IT_SOURCE(&huart2, UART_IT_TXE) != RESET))
    {
        if (tx_ser_i == tx_ser_o) {
            __HAL_UART_DISABLE_IT(&huart2, UART_IT_TXE);
            __HAL_UART_ENABLE_IT(&huart2, UART_IT_TC);
            tx_ser_cnt = 0;
        } else {
            huart2.Instance->DR = (uint8_t)(tx_ser_buf[TXBUF_MSK & tx_ser_o] & (uint8_t)0xFF);
            tx_ser_o++;
            tx_ser_cnt--;
        }
    }
    if((__HAL_UART_GET_FLAG(&huart2, UART_FLAG_TC) != RESET) &&
       (__HAL_UART_GET_IT_SOURCE(&huart2, UART_IT_TC) != RESET))
    {
        tx_ser_busy = 0;
        __HAL_UART_DISABLE_IT(&huart2, UART_IT_TC);
    }
    /* And never call default handler */
    return;
}


#endif /* SRC_UART_C_ */
