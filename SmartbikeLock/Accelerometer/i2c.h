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
//#define I2C_NACK()             I2C0_C1 |= I2C_C1_TXAK_MASK/*for sending NACK*/
//#define I2C_ACK()              I2C0_C1 &= ~I2C_C1_TXAK_MASK/*for sending ACK*/
//#define I2C_RS()               I2C0_C1 |= I2C_C1_RSTA_MASK/* for repeated start*/
//#define I2C_Rx()               I2C0_C1 &= ~I2C_C1_TX_MASK/*I2C in RX mode*/
void Init_I2C(I2C_Type* i2c);
void I2C_StartTx (char SlaveID, char Mode,I2C_Type* i2c);
void I2CWriteRegister(char SlaveID, char RegisterAddress, char Data,I2C_Type* i2c);
char I2CReadRegister(char SlaveID, char RegisterAddress,I2C_Type* i2c);
void I2CReadMultiRegisters(char SlaveID, char RegisterAddress, char n, char * r,I2C_Type* i2c);
void I2C_WRITE(I2C_Type* i2c,uint8_t data)__attribute__((always_inline));
void I2C_Start(I2C_Type* i2c)__attribute__((always_inline));
void I2C_Stop(I2C_Type* i2c)__attribute__((always_inline));
void I2C_Wait(I2C_Type* i2c)__attribute__((always_inline));
void I2C_NACK(I2C_Type* i2c)__attribute__((always_inline));
void I2C_ACK(I2C_Type* i2c)__attribute__((always_inline));
void I2C_RS(I2C_Type* i2c)__attribute__((always_inline));
void I2C_Rx(I2C_Type* i2c)__attribute__((always_inline));

#endif /* SOURCES_I2C_H_ */
