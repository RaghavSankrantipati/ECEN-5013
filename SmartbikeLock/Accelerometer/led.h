/*
 * led.h
 *
 *  Created on: Nov 16, 2016
 *      Author: moed4346
 */

#ifndef SOURCES_LED_H_
#define SOURCES_LED_H_
/* Timer0 Setup mod_value gives duty cycle*/
void TPM0_Setup(int mod_value);
/* Timer2 Setup mod_value gives duty cycle*/
void TPM2_Setup(int mod_value);
/*To glow Blue LED mod_value for intensity*/
void Blue(int mod_value);
/*To glow Red LED mod_value for intensity*/
void Red(int mod_value);
/*To glow Green LED mod_value for intensity*/
void Green(int mod_value);
/*To glow Yellow LED mod_value for intensity*/
void Yellow(int mod_value);
/*To glow violet LED mod_value for intensity*/
void violet(int mod_value);
/*To glow Cyan LED mod_value for intensity*/
void cyan(int mod_value);
/*To glow White LED mod_value for intensity*/
void white(int mod_value);
/*To switching off mod_value for intensity*/
void off(int mod_value);




#endif /* SOURCES_LED_H_ */
