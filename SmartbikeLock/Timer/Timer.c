/*
 * Timer.c
 *
 *  Created on: Dec 7, 2016
 *      Author: sasa6092
 */




#include "MKL25Z4.h"
#include "Timer.h"
#include "Temperature_main.h"
#include "Accelerometer_main.h"
#include "i2c.h"
#include "pressure.h"
#include "uart_ble.h"


void TPM2_Setup(void)

{
	MCG_BASE_PTR->C1 = MCG_C1_IREFS_MASK | MCG_C1_IRCLKEN_MASK; //internal clock is enable
	MCG_BASE_PTR->C2 = MCG_C2_IRCS_MASK; //Select fast internal clock
	SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM2_MASK; //Enable TPM2 clock
	SIM_BASE_PTR->SOPT2 |= SIM_SOPT2_TPMSRC(3); //MCGIR clock


	TPM2_BASE_PTR->SC = TPM_SC_CMOD(1) | TPM_SC_PS(7); //prescaler is set to 128
	TPM2_BASE_PTR->MOD = 16383;


	TPM2_BASE_PTR->SC |= TPM_SC_TOIE_MASK; //interrupt enable
	//NVIC_BASE_PTR->ISER = 1 << 19;

//    __enable_irq();
   NVIC_EnableIRQ(TPM2_IRQn);
}

 void TPM2_IRQHandler()
{
foo=pressure_main;
TPM2_BASE_PTR->SC |= TPM_SC_TOF_MASK; //clear interrupt
ADC_Init(); //intialise ADC and read temperature
Temp_Calibration(); //read temperature
foo();  //intialise and read pressure
ble_uart();
}
