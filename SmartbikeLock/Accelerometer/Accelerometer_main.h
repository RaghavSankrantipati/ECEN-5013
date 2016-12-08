/*
 * Accelerometer_main.h
 *
 *  Created on: Dec 7, 2016
 *      Author: moed4346
 */

#ifndef SOURCES_ACCELEROMETER_MAIN_H_
#define SOURCES_ACCELEROMETER_MAIN_H_
#include <stdint.h>
static int i = 0;
char data[6];
uint8_t f;
uint8_t CTRL_REG1_Data;
uint8_t Int_SourceSystem;
uint8_t Int_SourceTrans;
void Accelerometer_main();

void (*foo)();
#endif /* SOURCES_ACCELEROMETER_MAIN_H_ */
