/*  _______ _______        _______ ________ _______             ______        ______
 * |    ___|   |   |______|     __|  |  |  |    ___|    .--.--.|      |______|   __ \.----.-----.-----.
 * |    ___|       |______|__     |  |  |  |    ___|    |  |  ||   ---|______|    __/|   _|  _  |  _  |
 * |___|   |___|___|      |_______|________|___|        |_____||______|      |___|   |__| |_____|___  |
 *                                                                                              |_____|
 *  K7_0600-uartirq / uart.h
 *
 *  Code-Samples Lehrbrief "Mikrocontroller-Programmierung"
 *
 *  (c) Prof. Tobias Ellermeyer
 *      Fachhochschule Suedwestfalen
 *
 *  Last Update: SoSe 2023
 */
#ifndef INC_UART_H_
#define INC_UART_H_

// Define Buffer Sizes
#define RXBUF_LEN            128 // must be power of 2
#define TXBUF_LEN            128 // must be power of 2
#define RXBUF_MSK            (RXBUF_LEN-1)
#define TXBUF_MSK            (TXBUF_LEN-1)

#define UART_EMPTY 		255


void uart_init();

void uart_ser_putc(uint8_t);
uint8_t uart_ser_getc();

#endif
