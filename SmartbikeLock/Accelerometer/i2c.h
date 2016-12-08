/*
 * i2c.h
 *
 *  Created on: Nov 16, 2016
 *      Author: moed4346
 */
#include <stdint.h>
#include "MKL25Z4.h"
#ifndef SOURCES_I2C_H_
#define SOURCES_I2C_H_

#define WRITE                   0x00  /* Master write  */
#define READ                    0x01  /* Master read */
/*Initialising I2C.Activating Clocks and I2C GPIO return type is void 
The arguments can be I2C0,I2C1*/
void Init_I2C(I2C_Type* i2c);
/*Setup done for transmitting for selcting the slave and selection of mode
SlaveID-address of slave,Mode - read/write,I2C_Type - I2C0,I2C1*/
void I2C_StartTx (char SlaveID, char Mode,I2C_Type* i2c);
/*For writing to a regiter
SlaveID-address of slave,Register Address - address of register,Data - value you want to write to register I2C_Type - I2C0,I2C1*/
void I2CWriteRegister(char SlaveID, char RegisterAddress, char Data,I2C_Type* i2c);
/*For reading from a register
SlaveID-address of slave,Register Address - address of register, I2C_Type - I2C0,I2C1***/
char I2CReadRegister(char SlaveID, char RegisterAddress,I2C_Type* i2c);
/*for reading from multiple registers
SlaveID-address of slave,Register Address - address of register,n-how many registers to read r - pointer for the buffer I2C_Type - I2C0,I2C1*/
void I2CReadMultiRegisters(char SlaveID, char RegisterAddress, char n, char * r,I2C_Type* i2c);
/*for writing*/
/*i2c-I2C0,I2C1,data-data to be written*/
void I2C_WRITE(I2C_Type* i2c,uint8_t data)__attribute__((always_inline));
/*to send a start bit
i2c-I2C0/I2C1*/
void I2C_Start(I2C_Type* i2c)__attribute__((always_inline));
/* to send a stop bit
i2c-I2C0/I2C1*/
void I2C_Stop(I2C_Type* i2c)__attribute__((always_inline));
/* wait till ACk is recieved
i2c-I2C0/I2C1**/
void I2C_Wait(I2C_Type* i2c)__attribute__((always_inline));
/*send an NACK if it is the last byte to be read
i2c-I2C0/I2C1*/
void I2C_NACK(I2C_Type* i2c)__attribute__((always_inline));
/*send an ACK for reading more bytes of data
i2c-I2C0/I2C1**/
void I2C_ACK(I2C_Type* i2c)__attribute__((always_inline));
/*Send restart i2c-I2C0/I2C1**/
void I2C_RS(I2C_Type* i2c)__attribute__((always_inline));
/*for setting mode for reading using i2c i2c-I2C0/I2C1**/
void I2C_Rx(I2C_Type* i2c)__attribute__((always_inline));

#endif /* SOURCES_I2C_H_ */
