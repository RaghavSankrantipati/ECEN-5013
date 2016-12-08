/*
 * Accelerometer_main.c
 *
 *  Created on: Dec 7, 2016
 *      Author: moed4346
 */
#include "led.h"
#include "i2c.h"
#include "log.h"
#include "string.h"
#include "MKL25Z4.h"
#include "Accelerometer_main.h"
#include "uart_ble.h"

void Accelerometer_main()
{
	Init_I2C(I2C0);
	I2CWriteRegister(0x1D, 0x2A, 0x18,I2C0);
	I2CWriteRegister(0x1D, 0x1D, 0x16,I2C0);
	I2CWriteRegister(0x1D, 0x1F, 0x08,I2C0);
	I2CWriteRegister(0x1D, 0x20, 0x05,I2C0);
	I2CWriteRegister(0x1D, 0x2D, 0x20,I2C0);
	I2CWriteRegister(0x1D, 0x2E, 0x20,I2C0);
    CTRL_REG1_Data = I2CReadRegister(0x1D,0x2A,I2C0); //Read out the contents of the register
	CTRL_REG1_Data|= 0x01; //Change the value in the register to Active Mode.
	I2CWriteRegister(0x1D, 0x2A,CTRL_REG1_Data,I2C0);//Write in the updated value to put the device in
		                                            //Active Mode
	uint8_t str[]="I2C configuration done and in active mode\r";
	LOG(str,strlen(str));
		//f=I2CReadRegister(0x1D, 0x2A);
		//I2CReadMultiRegisters(0x1D, 0x01, 6, data);
}
void PORTA_IRQHandler(){
	PORTA_PCR14 |= PORT_PCR_ISF_MASK;
	Int_SourceSystem = I2CReadRegister(0x1D,0x0C,I2C0);
	if ((Int_SourceSystem & 0x20)==0x20)
	{
		uint8_t str[]="Motion detected, red led blinking \r ";
	    LOG(str,strlen(str));
		Red(32000);
	//Perform an Action since Transient Flag has been set
	//Read the Transient to clear system interrupt and Transient
	Int_SourceTrans = I2CReadRegister(0x1D,0x1E,I2C0);
	//Can parse out the data to perform a specific action based on the
	//axes or direction that made the condition true
	}
	//off(32000);
	tx_ble[5] = 100;
}

