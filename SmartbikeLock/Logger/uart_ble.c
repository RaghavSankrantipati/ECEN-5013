/*
 * uart_ble.c
 *
 *  Created on: Dec 8, 2016
 *      Author: sasa6092
 */

#include "MKL25Z4.h"
#include "core_cmFunc.h"
#include <stdio.h>
#include "uart_ble.h"

void ble_uart(void)
{
	uart0_init (SystemCoreClock,9600);
	while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
	uint8_t i = 0;
	while(i<6)
	{
		//while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
		UART0_D = tx_ble[i];
		i++;
	}
}
