#include "uart.h"
#include "led.h"
#include "Message.h"
#include "MKL25Z4.h"
/*
 * uart.c
 *
 *  Created on: Nov 1, 2016
 *      Author: moed4346
 */
/*void UART0_IRQHandler(){
	int i=0, value=0, intensity=0, mod_value=32000,result;
	char d;
	   //time_t start_t, end_t;
	  // double diff_t;
	while(!(UART0_S1 & UART_S1_RDRF_MASK));
	Bluep.command=UART0_D;
	while(!(UART0_S1 & UART_S1_RDRF_MASK));
		Bluep.length=UART0_D;
		while(!(UART0_S1 & UART_S1_RDRF_MASK));
				Bluep.data[0]=UART0_D;
				while(!(UART0_S1 & UART_S1_RDRF_MASK));
								Bluep.checksum=UART0_D;
								result=validate_checksum();
	if(result==1)
		{*/
	/*if(value==0)
	{

		off(mod_value);

	}*/
/*
	if(Bluep.command==LED_BLUE)
	{
		//time(&start_t);
		//off(mod_value);
		Red(mod_value);
		//time(&end_t);
		//diff_t = difftime(end_t, start_t);

	}
	/*
	if(value==2)
	{
		time(&start_t);
		off(mod_value);
		Blue(mod_value);
		time(&end_t);
		diff_t = difftime(end_t, start_t);
	}
	if(value==3)
	{
		time(&start_t);
		off(mod_value);
		Green(mod_value);
		time(&end_t);
		diff_t = difftime(end_t, start_t);
	}
	if(value==4)
	{
		off(mod_value);
		Yellow(mod_value);
	}
	if(value==5)
	{
		off(mod_value);
		violet(mod_value);
	}
	if(value==6)
	{
		off(mod_value);
		cyan(mod_value);
	}
	if(value==7)
	{
		off(mod_value);
		white(mod_value);
	}
	if(value<0||value>7)
	{
		off(mod_value);
		value=0;
	}*/

	//}
	//}//putchar(s);//d = UART0_D ;
	//__disable_irq();
/*void uart0_init (int sysclk, int baud)
{
    uint32_t sbr_val, uart0clk;
    uint32_t baud_rate;
  // For enabling UART0
    SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
   // SIM_SOPT2 &= ~SIM_SOPT2_UART0SRC_MASK;
    SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1);
    // Configuration for GPIO
    /* Turn on clock to PortA module */
    // Configuration for Step 1 and Step 2
    	//SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
    	//PORTA_PCR1= PORT_PCR_PE(1);// Pull Enable to Enable PortA14
    	//PORTA_PCR1 = PORT_PCR_MUX(2); // Selecting MUX bits and Select ALT 2
    	//PORTA_PCR2= PORT_PCR_PE(1); // Pull Enable to Enable PortA15
    	//PORTA_PCR2 = PORT_PCR_MUX(2); // Selecting MUX bits and Select ALT 2


    // Configuration for Step 3
    // Disable RX/TX before changing registers
    //UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);
    	//UART0_C2=0x00;

    //Configuration for Step 4
    	//UART0_BDH|=UART0_BDH_SBNS(0);
   // UART0_C1 |= ~(UART0_C1_PE_MASK | UART0_C1_M_MASK | UART0_C1_LOOPS_MASK); // Changes for no parity, 8 bit mode, loop normal

    // Configuration for step 5
    // Initialize baud rate
  //uint32_t baud_divisor;
 // baud_divisor = (sysclk/16)/baud ;
//  UART0_BDH =((baud_divisor>>8) & UART_BDH_SBR_MASK);
//  UART0_BDL =(baud_divisor & UART_BDL_SBR_MASK);
        // Configuration for Step 6
        // Enable Interrupts for TX/RX
       //UART0_C2 |= UART_C2_RIE_MASK;
        		//UART0_C2 |=	UART0_C2_TE_MASK|UART0_C2_RE_MASK;
        		//UART0_S1|=0xC0;
        		// __enable_irq();
      // NVIC_EnableIRQ(UART0_IRQn);

    // }
/*int validate_checksum()
{
	uint16_t c= Bluep.command^Bluep.length^Bluep.data[0];
	if(Bluep.checksum==c)
		return 0;
	else
		return 1;
}*/



