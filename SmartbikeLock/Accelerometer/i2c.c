/*
 * i2c.c
 *
 *  Created on: Nov 29, 2016
 *      Author: moed4346
 */

#include "i2c.h"
#include "MKL25Z4.h"
#include "log.h"
#include "string.h"
void Init_I2C(I2C_Type* i2c)
{
  SIM_SCGC5 = SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTE_MASK;// Turn on clock to PortA and Port E module
  if(i2c==I2C0)
  {
  SIM_SCGC4 |= SIM_SCGC4_I2C0_MASK;  // Turn on clock to I2C0 module
  PORTE_PCR24 = PORT_PCR_MUX(5);  // PTE24 pin is I2C0 SCL line
  PORTE_PCR25 = PORT_PCR_MUX(5);  // PTE25 pin is I2C0 SDA line
  uint8_t str[]="\r I2C0 Initialised\r";
  LOG(str,strlen(str));
  }
  else
  {
	  SIM_SCGC4 |= SIM_SCGC4_I2C1_MASK;
	  PORTE_PCR0 = PORT_PCR_MUX(6);  // PTE24 pin is I2C0 SCL line
	  PORTE_PCR1 = PORT_PCR_MUX(6);  //initialise the scl and sda
	  uint8_t str[]="\r I2C1 Initialised\r";
	  LOG(str,strlen(str));
  }



  I2C_F_REG(i2c) = I2C_F_MULT(0x00) | I2C_F_ICR(0x12); /* divide by 64 instead, so 375 kHz */
  I2C_C1_REG(i2c) = I2C_C1_IICEN_MASK;  /* enable the I2C module */
  PORTA_PCR14 |= (0|PORT_PCR_ISF_MASK|     // Clear the interrupt flag
  	     	                       PORT_PCR_MUX(0x1)|     // PTA14 is configured as GPIO
  	     	                       PORT_PCR_IRQC(0xA));   // PTA14 is configured for falling edge interrupts

  	     	        //Enable PORTA interrupt on NVIC
  __enable_irq();
  NVIC_EnableIRQ(PORTA_IRQn);
}
void inline I2C_WRITE(I2C_Type* i2c,uint8_t data)
{
	I2C_D_REG(i2c) = data; 		//write data
}
void inline I2C_Start(I2C_Type* i2c)
{
	I2C_C1_REG(i2c) |= I2C_C1_TX_MASK; // enable transfer
	I2C_C1_REG(i2c) |= I2C_C1_MST_MASK;
}
void inline I2C_Stop(I2C_Type* i2c)
{
	I2C_C1_REG(i2c) &= ~I2C_C1_MST_MASK; // disable transfer
	I2C_C1_REG(i2c) &= ~I2C_C1_TX_MASK;
}
void inline I2C_Wait(I2C_Type* i2c)
{
	 while((I2C_S_REG(i2c) & I2C_S_IICIF_MASK)==0);  // wait for interrupt flag
	 I2C_S_REG(i2c) |= I2C_S_IICIF_MASK;
}
void inline I2C_NACK(I2C_Type* i2c)
{
	I2C_C1_REG(i2c) |= I2C_C1_TXAK_MASK; //enable transfer acknowledge
}
void inline I2C_ACK(I2C_Type* i2c)
{
	I2C_C1_REG(i2c) &= ~I2C_C1_TXAK_MASK; //disable transfer acknowledge
}
void inline I2C_RS(I2C_Type* i2c)
{
	I2C_C1_REG(i2c) |= I2C_C1_RSTA_MASK; //repeat start condition enable
}
void inline I2C_Rx(I2C_Type* i2c)
{
	I2C_C1_REG(i2c) &= ~I2C_C1_TX_MASK; //disable repeat condition
}
void I2C_StartTx (char SlaveID, char Mode,I2C_Type* i2c)
{
  SlaveID = SlaveID << 1;
  SlaveID |= (Mode & 0x01);
  I2C_Start(i2c); //Start I2C
  I2C_WRITE(i2c,SlaveID);  //Write I2C
}

void Pause(void){
    int n;
    for(n=1;n<50;n++) {
    }
}
char I2CReadRegister(char SlaveID, char RegisterAddress,I2C_Type* i2c)
{
  char result;

  I2C_StartTx(SlaveID,WRITE,i2c);
  I2C_Wait(i2c);
  I2C_WRITE(i2c,RegisterAddress);
  I2C_Wait(i2c);
  I2C_RS(i2c);
  I2C_WRITE(i2c,(SlaveID << 1) | READ);
  I2C_Wait(i2c);
  I2C_Rx(i2c);
  I2C_NACK(i2c);// Send NACK to tell dat dis is last transmission
  result = I2C_D_REG(i2c) ; //In master receive mode, reading this register
                       // initiates receiving of the next byte of data.
  I2C_Wait(i2c);
  I2C_Stop(i2c); // Send Stop
  result = I2C_D_REG(i2c) ; // reading the register
  Pause();
  return result;
}

void I2CWriteRegister(char SlaveID, char RegisterAddress, char Data,I2C_Type* i2c)
{
  I2C_StartTx(SlaveID,WRITE,i2c);
  I2C_Wait(i2c);
  I2C_WRITE(i2c,RegisterAddress);
  I2C_Wait(i2c);
  I2C_WRITE(i2c,Data);
  I2C_Wait(i2c);
  I2C_Stop(i2c);
  Pause();
}
void I2CReadMultiRegisters(char SlaveID, char RegisterAddress, char n, char * r,I2C_Type* i2c)
{
  char i;
  I2C_StartTx(SlaveID,WRITE,i2c);
  I2C_Wait(i2c);
  I2C_WRITE(i2c,RegisterAddress);
  I2C_Wait(i2c);
  I2C_RS(i2c);
  I2C_WRITE(i2c,(SlaveID << 1) | 0x01);
  I2C_Wait(i2c);
  I2C_Rx(i2c);
  I2C_ACK(i2c);
  i = I2C_D_REG(i2c);
  for(i=0;i<n-2;i++)
  {
    *r =I2C_D_REG(i2c);
    r++;
    I2C_Wait(i2c);
  }
  I2C_NACK(i2c);
  *r = I2C_D_REG(i2c);
  r++;
  I2C_Wait(i2c);
  I2C_Stop(i2c);
  *r = I2C_D_REG(i2c);
  Pause();
}

