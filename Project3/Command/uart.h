/*
 * uart.h
 *
 *  Created on: Nov 1, 2016
 *      Author: moed4346
 */

#ifndef SOURCES_UART_H_
#define SOURCES_UART_H_

void uart0_init (int sysclk, int baud);

int validate_checksum();

#endif /* SOURCES_UART_H_ */
