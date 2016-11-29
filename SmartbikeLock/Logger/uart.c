/*
 * uart.c
 *
 *  Created on: Oct 12, 2016
 *      Author: raghav
 */





#include "MKL25Z4.h"
//#include "core_cm4.h"
#include "core_cmFunc.h"
#include "uart.h"
#include <stdio.h>
/***************************************************************************
 * Begin UART0 functions
 **************************************************************************/
/********************************************************************/
/*
 * Initialize the uart for 8N1 operation, interrupts disabled, and
 * no hardware flow-control
 * Parameters:
 *  sysclk      uart module Clock in kHz(used to calculate baud)
 *  baud        uart baud rate
 */

void uart0_init (int sysclk, int baud)
{
    uint32_t sbr_val, uart0clk;
    uint32_t baud_rate;
  // For enabling UART0
    SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
    SIM_SOPT2 &= ~SIM_SOPT2_UART0SRC_MASK;
    SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1);
    // Configuration for GPIO
    /* Turn on clock to PortA module */
    // Configuration for Step 1 and Step 2
    SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
    //PORTA_PCR1= PORT_PCR_PE(1);// Pull Enable to Enable PortA14
    PORTA_PCR1 = PORT_PCR_MUX(2); // Selecting MUX bits and Select ALT 2
    //PORTA_PCR2= PORT_PCR_PE(1); // Pull Enable to Enable PortA15
    PORTA_PCR2 = PORT_PCR_MUX(2); // Selecting MUX bits and Select ALT 2


    // Configuration for Step 3
    // Disable RX/TX before changing registers
    //UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);
    UART0_C2=0x00;

    //Configuration for Step 4
    UART0_BDH|=UART0_BDH_SBNS(0);
    UART0_C1 |= ~(UART0_C1_PE_MASK | UART0_C1_M_MASK |
UART0_C1_LOOPS_MASK); // Changes for no parity, 8 bit mode, loop

    // Configuration for step 5
    // Initialize baud rate
  uint32_t baud_divisor;
  baud_divisor = (sysclk/16)/baud ;
  UART0_BDH =((baud_divisor>>8) & UART_BDH_SBR_MASK);
  UART0_BDL =(baud_divisor & UART_BDL_SBR_MASK);
        // Configuration for Step 6
        // Enable Interrupts for TX/RX
       UART0_C2 |= UART_C2_TIE_MASK;
        UART0_C2 |= UART0_C2_TE_MASK|UART0_C2_RE_MASK;
        //UART0_S1|=0xC0;
        __enable_irq();
       NVIC_EnableIRQ(UART0_IRQn);

     }
