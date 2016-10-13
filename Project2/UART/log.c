#include "log.h"
#include "uart.h"
#include "string.h"
//#include "Buffer.h"
#include "MKL25Z4.h"
#include "itoa.h"
#include "ftoa.h"
static int i = 0;
int j=0;


void LOG(char *s,int l)
{
	uart0_init (SystemCoreClock,38400);
		while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
		while(i<l)
		{
		UART0_D=*(s+i);
		i++;
		for(int k=0;k<700;k++);
		}
		i=0;
}
void LOG1(char *p,int l,float param,int data_type_size)
{
	//uart0_init(SystemCoreClock,38400);
	//while(!(UART0_S1 & UART_S1_RDRF_MASK));
//for(int i=0;i<1000;i++);
char par[l];
//my_itoa(par,param,10);
ftoa(param, par, 3);
char* str=strcat(p,par);
LOG(str,strlen(str));
}
/*void UART0_IRQHandler(){
	while(j<3)
	{
while(!(UART0_S1 & UART_S1_RDRF_MASK));
		*(s1+j)=UART0_D;
		//for(int i=0;i<700;i++);
j++;
	//__disable_irq();
		//for(int j=0;j<700;j++);
}*/

//}
