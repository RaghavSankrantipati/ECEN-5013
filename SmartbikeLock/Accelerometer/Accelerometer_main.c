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
#include "MMA8451q.h"
#define Acceler_address 0x1D
#define CTRL1_REG_ADDR  0x2A
#define CONFIG_REG_ADDR 0x1D
#define THRS_REG_ADDR   0x1F
#define DBNS_REG_ADDR   0x20
#define CTRL_REG4_ADDR  0x2D
#define CTRL_REG5_ADDR  0x2E
#define CTRL1_REG_VAL  0x18
#define CONFIG_REG_VAL 0x16
#define THRS_REG_VAL   0x08
#define DBNS_REG_VAL   0x05
#define CTRL_REG4_VAL  0x20
#define CTRL_REG5_VAL  0x20
#define ACC_ACTIVEMODE 0x01
void Accelerometer_main()
{
	Init_I2C(I2C0);
	I2CWriteRegister( Acceler_address, CTRL1_REG_ADDR, CTRL1_REG_VAL,I2C0);
	I2CWriteRegister( Acceler_address, CONFIG_REG_ADDR, CONFIG_REG_VAL,I2C0);
	I2CWriteRegister( Acceler_address, THRS_REG_ADDR, THRS_REG_VAL,I2C0);
	I2CWriteRegister( Acceler_address, DBNS_REG_ADDR, DBNS_REG_VAL,I2C0);
	I2CWriteRegister( Acceler_address, CTRL_REG4_ADDR, CTRL_REG4_VAL,I2C0);
	I2CWriteRegister( Acceler_address, CTRL_REG5_ADDR, CTRL_REG5_VAL,I2C0);
    CTRL_REG1_Data = I2CReadRegister( Acceler_address,CTRL1_REG_ADDR,I2C0); //Read out the contents of the register
	CTRL_REG1_Data|= ACC_ACTIVEMODE; //Change the value in the register to Active Mode.
	I2CWriteRegister( Acceler_address, CTRL1_REG_ADDR,CTRL_REG1_Data,I2C0);//Write in the updated value to put the device in
		                                            //Active Mode
	uint8_t str[]="I2C configuration done and in active mode\r";
	LOG(str,strlen(str));
}
void PORTA_IRQHandler(){
	PORTA_PCR14 |= PORT_PCR_ISF_MASK;
	Int_SourceSystem = I2CReadRegister( Acceler_address,0x0C,I2C0);
	if ((Int_SourceSystem & 0x20)==0x20)
	{
		uint8_t str[]="Motion detected, red led blinking \r ";
	    LOG(str,strlen(str));
		Red(32000);
	//Perform an Action since Transient Flag has been set
	//Read the Transient to clear system interrupt and Transient
	Int_SourceTrans = I2CReadRegister( Acceler_address,0x1E,I2C0);
	//Can parse out the data to perform a specific action based on the
	//axes or direction that made the condition true
	}
	//off(32000);
	tx_ble[5] = 100;
}

