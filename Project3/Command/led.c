/*
 * led.c
 *
 *  Created on: Nov 1, 2016
 *      Author: moed4346
 */
#include "led.h"
#include "MKL25Z4.h"

void TPM2_Setup(int mod_value)
{
	MCG_BASE_PTR->C1 = MCG_C1_IREFS_MASK | MCG_C1_IRCLKEN_MASK;
	MCG_BASE_PTR->C2 = MCG_C2_IRCS_MASK;
	SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM2_MASK;
	SIM_BASE_PTR->SOPT2 |= SIM_SOPT2_TPMSRC(3);
	TPM2_BASE_PTR->SC = TPM_SC_CMOD(1) | TPM_SC_PS(7);
		//LPTPM counter increments on every LPTPM counter clock
		//prescalar 128
		TPM2_BASE_PTR->MOD = mod_value;
}
void TPM0_Setup(int mod_value)
{
	MCG_BASE_PTR->C1 = MCG_C1_IREFS_MASK | MCG_C1_IRCLKEN_MASK;
				MCG_BASE_PTR->C2 = MCG_C2_IRCS_MASK; //Select fast internal clock
				SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM0_MASK; //Enable TPM2 clock
				SIM_BASE_PTR->SOPT2 |= SIM_SOPT2_TPMSRC(3);
				TPM0_BASE_PTR->SC = TPM_SC_CMOD(1) | TPM_SC_PS(7);
				TPM0_BASE_PTR->MOD = mod_value;
}
void Red(int mod_value)
{
	TPM2_Setup(mod_value);
	SIM_BASE_PTR->SCGC5 |=SIM_SCGC5_PORTB_MASK;
	PORTB_BASE_PTR->PCR[18] =PORT_PCR_MUX(3);
	GPIOB_PDDR= 1<<18;
	TPM2_BASE_PTR->CONTROLS[0].CnSC=TPM_CnSC_MSB_MASK|TPM_CnSC_ELSA_MASK;
	TPM2_BASE_PTR->CONTROLS[0].CnV=TPM2_BASE_PTR->MOD;
}
void Green(int mod_value)
{
	TPM2_Setup(mod_value);
	SIM_BASE_PTR->SCGC5 |=SIM_SCGC5_PORTB_MASK;
		PORTB_BASE_PTR->PCR[19] =PORT_PCR_MUX(3);
		GPIOB_PDDR= 1<<19;
		TPM2_BASE_PTR->CONTROLS[1].CnSC=TPM_CnSC_MSB_MASK|TPM_CnSC_ELSA_MASK;
		TPM2_BASE_PTR->CONTROLS[1].CnV=TPM2_BASE_PTR->MOD;
}
void Blue(int mod_value)
{
	TPM0_Setup(mod_value);
	SIM_BASE_PTR->SCGC5 |=SIM_SCGC5_PORTD_MASK;
	PORTD_BASE_PTR->PCR[1] =PORT_PCR_MUX(4);
				GPIOD_PDDR= 1<<1;
				TPM0_BASE_PTR->CONTROLS[1].CnSC=TPM_CnSC_MSB_MASK|TPM_CnSC_ELSA_MASK;
				TPM0_BASE_PTR->CONTROLS[1].CnV=TPM0_BASE_PTR->MOD;
}
void violet(int mod_value)
{
	Red (mod_value);
	Blue(mod_value);
}
void cyan(int mod_value)
{
	Green(mod_value);
	Blue(mod_value);
}
void white(int mod_value)
{
	Red(mod_value);
	Green(mod_value);
	Blue(mod_value);
}
void Yellow(int mod_value)
{
	Red(mod_value);
	Green(mod_value);
}
void off(int mod_value)
{
	white(mod_value);
	PORTB_BASE_PTR->PCR[18] =PORT_PCR_MUX(1);
	PORTB_BASE_PTR->PCR[19] =PORT_PCR_MUX(1);
	PORTD_BASE_PTR->PCR[1] =PORT_PCR_MUX(1);
//	SIM_BASE_PTR->SCGC6 &= ~SIM_SCGC6_TPM0_MASK;
//	SIM_BASE_PTR->SCGC6 &= ~SIM_SCGC6_TPM0_MASK;
    GPIOB_PSOR=GPIO_PCOR_PTCO_MASK;
    GPIOD_PSOR=GPIO_PCOR_PTCO_MASK;

}


