/*
 * led.c
 *
 *  Created on: Nov 16, 2016
 *      Author: moed4346
 */
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

#include "MKL25Z4.h"
#include "led.h"
/*Timer2 Initialisation */
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
/*Timer2 Initialisation */
void TPM0_Setup(int mod_value)
{
	MCG_BASE_PTR->C1 = MCG_C1_IREFS_MASK | MCG_C1_IRCLKEN_MASK;
				MCG_BASE_PTR->C2 = MCG_C2_IRCS_MASK; //Select fast internal clock
				SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM0_MASK; //Enable TPM2 clock
				SIM_BASE_PTR->SOPT2 |= SIM_SOPT2_TPMSRC(3);
				TPM0_BASE_PTR->SC = TPM_SC_CMOD(1) | TPM_SC_PS(7);
				TPM0_BASE_PTR->MOD = mod_value;
}
/*For glowing Red LED*/
void Red(int mod_value)
{
	TPM2_Setup(mod_value);
	SIM_BASE_PTR->SCGC5 |=SIM_SCGC5_PORTB_MASK;
	PORTB_BASE_PTR->PCR[18] =PORT_PCR_MUX(3);
	GPIOB_PDDR= 1<<18;
	TPM2_BASE_PTR->CONTROLS[0].CnSC=TPM_CnSC_MSB_MASK|TPM_CnSC_ELSA_MASK;
	TPM2_BASE_PTR->CONTROLS[0].CnV=TPM2_BASE_PTR->MOD;
}
/*For glowing Green LED**/
void Green(int mod_value)
{
	TPM2_Setup(mod_value);
	SIM_BASE_PTR->SCGC5 |=SIM_SCGC5_PORTB_MASK;
		PORTB_BASE_PTR->PCR[19] =PORT_PCR_MUX(3);
		GPIOB_PDDR= 1<<19;
		TPM2_BASE_PTR->CONTROLS[1].CnSC=TPM_CnSC_MSB_MASK|TPM_CnSC_ELSA_MASK;
		TPM2_BASE_PTR->CONTROLS[1].CnV=TPM2_BASE_PTR->MOD;
}
/*For glowing Blue LED**/
void Blue(int mod_value)
{
	TPM0_Setup(mod_value);
	SIM_BASE_PTR->SCGC5 |=SIM_SCGC5_PORTD_MASK;
	PORTD_BASE_PTR->PCR[1] =PORT_PCR_MUX(4);
				GPIOD_PDDR= 1<<1;
				TPM0_BASE_PTR->CONTROLS[1].CnSC=TPM_CnSC_MSB_MASK|TPM_CnSC_ELSA_MASK;
				TPM0_BASE_PTR->CONTROLS[1].CnV=TPM0_BASE_PTR->MOD;
}
/*For glowing violet LED**/
void violet(int mod_value)
{
	Red (mod_value);
	Blue(mod_value);
}
/*For glowing Cyan LED**/
void cyan(int mod_value)
{
	Green(mod_value);
	Blue(mod_value);
}
/*For glowing white LED*/
void white(int mod_value)
{
	Red(mod_value);
	Green(mod_value);
	Blue(mod_value);
}
/*For glowing Yellow LED*/
void Yellow(int mod_value)
{
	Red(mod_value);
	Green(mod_value);
}
/*For switching OFF**/
void off(int mod_value)
{
	white(mod_value);
	PORTB_BASE_PTR->PCR[18] =PORT_PCR_MUX(1);
	PORTB_BASE_PTR->PCR[19] =PORT_PCR_MUX(1);
	PORTD_BASE_PTR->PCR[1] =PORT_PCR_MUX(1);
        GPIOB_PSOR=GPIO_PCOR_PTCO_MASK;
        GPIOD_PSOR=GPIO_PCOR_PTCO_MASK;

}
