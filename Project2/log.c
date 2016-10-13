/*
 * log.c
 *
 *  Created on: Oct 11, 2016
 *      Author: raghav
 */
#include "uart.h"
#include "MKL25Z4.h"
int i=0;
void log(char *p,int len)
{
	uart0_init (SystemCoreClock,38400);
	while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
	while(i<len)
	{
	UART0_D=*(p+i);
	i++;
	for(int k=0;k<700;k++);
	}
	i=0;
}



