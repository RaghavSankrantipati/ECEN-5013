#include "log.h"
#include "uart.h"
#include "string.h"
#include "MKL25Z4.h"
#include "itoa.h"
#include "Circ_Buff.h"
static int i = 0;
uint8_t Buffer[1000];
int j=0;
void LOG(char *s,int l)
{
	a.Buffer=Buffer;
	        a.HEAD=Buffer;
	        a.TAIL=Buffer;
	uart0_init (SystemCoreClock,38400);
		while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
		while(i<l)
		{
		add_data(&a,*(s+i),1000);
		UART0_D=get_data(&a,1000);
		i++;
		for(int k=0;k<700;k++);
		}
		i=0;
}
void LOG1(char *p,int l,int param,int data_type_size)
{
char par[l];
my_itoa(par,param ,10);
char* str=strcat(p,par);
LOG(str,strlen(str));
}
