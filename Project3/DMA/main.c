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
#include<stdint.h>
#include<string.h>
#include"stdlib.h"
#include"log.h"
void start();
void TPM2_Setup();
int stop();
void dma_init();
uint32_t length=5000;
uint8_t s[5000];
uint8_t d[5000];
int main(void)
{
/*
	for(int i=0;i<length;i++)
	{
		s[i]=0;
	}*/
	dma_init();
	start();
	DMA_DCR0|=DMA_DCR_START_MASK;
    /* Write your code here */
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
void dma_init()
{
	SIM->SCGC6|=SIM_SCGC6_DMAMUX_MASK;// Enable clock to DMA mux
	SIM->SCGC7|=SIM_SCGC7_DMA_MASK;// Enable clock to DMA
	DMAMUX0->CHCFG[0]=0;//before writing ckear the registers
	DMA0->DMA[0].DSR_BCR=DMA_DSR_BCR_DONE_MASK;// Writing a 1 to this bit clears all DMA status bits
	DMA0->DMA[0].DSR_BCR|=DMA_DSR_BCR_BCR_MASK&length;//no of bytes
	DMA0->DMA[0].SAR=(uint32_t) s;//source address
	DMA0->DMA[0].DAR=(uint32_t) d;//destination address
	//DMA0->DMA[0].DCR=DMA_DCR_EINT_MASK|DMA_DCR_AA_MASK|DMA_DCR_SSIZE(0x00)|DMA_DCR_DSIZE(0x00)|DMA_DCR_START_MASK;
	DMA0->DMA[0].DCR=DMA_DCR_EINT_MASK|DMA_DCR_AA_MASK|DMA_DCR_SSIZE(0x01)|DMA_DCR_DSIZE(0x01);//(for 8-bit)
	//DMA0->DMA[0].DCR=DMA_DCR_EINT_MASK|DMA_DCR_AA_MASK|DMA_DCR_SSIZE(0x00)|DMA_DCR_DSIZE(0x00);//(for 32-bit)
	/*enable interrupt on the completion
	 * Auto-align
	 * Source size 32-bit
	 * destination size 32-bit
	 * start transfer
	 */
	DMAMUX0->CHCFG[0]=DMAMUX_CHCFG_ENBL_MASK|DMAMUX_CHCFG_SOURCE(60);
	__enable_irq();
	NVIC_EnableIRQ(DMA0_IRQn);
	/*
	 * Enable the DMA,
	 * selecting the normal always enabled DMA
	 */
}
void DMA0_IRQHandler()
{
	int time1=stop();
	char str[]="DMA time for moving 10 using 8-bit in us:";
	//char str[]="DMA time for zero 10 using 8-bit in us:";
	int l=strlen(str);
	LOG1(str,l,time1,8);
	start();
			memmove(s,d,5000);
			//memset(s,0,5000);
			int time2=stop();
			char str1[]="Inbuilt time for moving 10 in us:";
			//char str1[]="Inbuilt time for zero 10 in us:";
				int l1=strlen(str1);
				LOG1(str1,l1,time2,8);
	__disable_irq();
}
void TPM2_Setup()
{
	SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM2_MASK;
	SIM_BASE_PTR->SOPT2 |= SIM_SOPT2_TPMSRC(1);
	TPM2_BASE_PTR->SC = TPM_SC_CMOD(1) | TPM_SC_PS(0);
	TPM2_BASE_PTR->MOD = 32000;
	TPM2_BASE_PTR->CONTROLS[0].CnSC=TPM_CnSC_MSB_MASK|TPM_CnSC_ELSA_MASK;
	TPM2_BASE_PTR->CONTROLS[0].CnV=TPM2_BASE_PTR->MOD;
}

void start()
{
	TPM2_Setup();
}
int stop()
{
	TPM2_BASE_PTR->SC = TPM_SC_CMOD(0);
	int count=TPM2_CNT;
	int x=count/21;
	return x;
}
