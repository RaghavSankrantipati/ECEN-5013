/*
 * Message.c
 *
 *  Created on: Nov 1, 2016
 *      Author: moed4346
 */
#include "Message.h"
#include "uart.h"
#include "MKL25Z4.h"
int i=0;
/*
void message_tx(void)
{
	CI_Msg Blue;
Blue.command=LED_BLUE;
Blue.length=5;
Blue.data[0]=4;
Blue.checksum=Blue.command^Blue.length^Blue.data[0];
//Blue.checksum=cal_check();
	while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
	UART0_D=Blue.command;
	while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
		UART0_D=Blue.length;
		while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
				UART0_D=Blue.data[0];
				while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
								UART0_D=Blue.checksum;
}*/

/*uint16_t cal_check()
{
	uint16_t result;
	result=Blue.command^Blue.length^Blue.data[0];
	return(result);
}*/



