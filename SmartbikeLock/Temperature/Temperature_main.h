/*
 * Temperature.h
 *
 *  Created on: Dec 7, 2016
 *      Author: moed4346
 */

#ifndef SOURCES_TEMPERATURE_MAIN_H_
#define SOURCES_TEMPERATURE_MAIN_H_

void ADC_Init(void);
uint16_t TEMP_Read(void);
void Temp_Calibration(void);



#endif /* SOURCES_TEMPERATURE_MAIN_H_ */
