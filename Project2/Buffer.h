/*
 * Buffer.h
 *
 *  Created on: Oct 11, 2016
 *      Author: raghav
 */

#ifndef SOURCES_BUFFER_H_
#define SOURCES_BUFFER_H_
#include<stdio.h>
#include<stdint.h>
typedef struct
{
uint8_t* HEAD;
uint8_t* TAIL;
uint8_t* Buffer;
}structure;
char *d;
enum BUFFER_STATE {BUFFER_FULL,BUFFER_EMPTY};
//uint8_t length=4;
uint8_t add_data(structure *s,uint8_t Value,uint8_t length);
uint8_t Buffer_Full(structure *s,uint8_t length);
uint8_t Buffer_Empty(structure *s);
uint8_t remove_data(structure *s);
uint8_t get_data(structure *s);
void Buffer_init();
void release(char *s);
#endif /* SOURCES_BUFFER_H_ */
