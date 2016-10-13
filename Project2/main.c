/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include"Buffer.h"
#include "uart.h"
#include <string.h>
#include "MKL25Z4.h"
//char t[]="I am Mounika";
structure a;
structure b;
int i=0;
int len=15;
int main(void)
{
	Buffer_init();
a.Buffer=d;
a.HEAD=d;
a.TAIL=d;
b.Buffer=s;
b.HEAD=s;
b.TAIL=s;
uart0_init (SystemCoreClock,38400);
}
void UART0_IRQHandler()
		{

			while(i<len){
				while(!(UART0_S1 & UART_S1_RDRF_MASK));
					*(d+i)=UART0_D;
					for(int j=500;j>0;j--);
					while(!(UART0_S1 & UART_S1_TDRE_MASK));
					add_data(&a,*(d+i),len);
					add_data(&b,*(s+i),len);
				UART0_D=get_data(&a);
				i++;
                 }
			__disable_irq();
			release(d);
			release(s);
		}
/*
void LOG(structure *s,int l)
{
	structure a;
			a.Buffer=t;
			a.HEAD=t;
			a.TAIL=t;

	uart_transmit(&a,l);
}
void uart_transmit(structure *a,int l)
{
	uart0_init(SystemCoreClock,38400);
while(i<l)
{
	while((add_data(&a,*(t+i),l)));
if ((UART0_S1 & UART_S1_TDRE_MASK))
{
        UART0_D = get_data(&a);
        if(Buffer_Empty(&a))
        UART0->C2 &= ~UART_C2_TIE_MASK;//disable the transmit interrupt
        for(int k=0;k<700;k++);
}
i++;
}
}*/
//////////////////////////////////////////////////
