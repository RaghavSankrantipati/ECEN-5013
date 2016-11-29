/*
 * Circ_buff.h
 *
 *  Created on: Nov 28, 2016
 *      Author: moed4346
 */
#include <stdint.h>
#include <stdio.h>
#ifndef SOURCES_CIRC_BUFF_H_
#define SOURCES_CIRC_BUFF_H_
typedef struct
{
uint8_t* HEAD;
uint8_t* TAIL;
uint8_t* Buffer;
}structure;
char *g;
enum BUFFER_STATE {BUFFER_FULL,BUFFER_EMPTY};
//uint8_t length=4;
uint8_t add_data(structure *s,uint8_t Value,uint8_t length);
uint8_t Buffer_Full(structure *s,uint8_t length);
uint8_t Buffer_Empty(structure *s);
uint8_t remove_data(structure *s);
uint8_t get_data(structure *s,uint8_t length);
uint32_t Buffer_init();
void release(char *s);
#endif /* SOURCES_CIRC_BUFF_H_ */
