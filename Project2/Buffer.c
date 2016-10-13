/*
 * Buffer.c

 *
 *  Created on: Oct 11, 2016
 *      Author: raghav
 */
#include"Buffer.h"
#include "log.h"
#include<stdlib.h>

//uint8_t length=4;
/**** adding the data to the circular buffer***/
uint8_t add_data(structure *s,uint8_t Value,uint8_t length)
{
/*** check before writing the values whether the buffer is full****/
if(Buffer_Full(s,length))
{
//printf("Buffer is full");
	char s[]="Buffer is full";
	log(s,strlen(s));
return -1;
}
else
{
*s->HEAD= Value;/*** writing the value onto the HEAD**/
 s->HEAD++;
return 0;
}
}
/****Buffer full****/
uint8_t Buffer_Full(structure *s,uint8_t length)
{
if(s->HEAD==(s->Buffer + (length-1)*(sizeof(uint8_t))))
{
s->HEAD=s->Buffer;
	return 1;
}
else
return 0;
}
/****Buffer Empty****/
uint8_t Buffer_Empty(structure *s)
{
if((s->HEAD)==(s->TAIL))
return 1;
else
return 0;
}
/**** Buffer Remove*****/
uint8_t remove_data(structure *s)
{
if(Buffer_Empty(s))
{
//printf("Buffer is Empty");
	char s[]="Buffer is Empty";
	log(s,strlen(s));
return -1;
}
else
{
s->TAIL++;
return 0;
}
}
uint8_t get_data(structure *s)
{
/*** check before writing the values whether the buffer is full****/
if(Buffer_Empty(s))
{
//printf("Buffer is Empty");
	char s[]="Buffer is Empty";
	log(s,strlen(s));
return -1;
}
else
{
*s->HEAD--;
return(*s->HEAD);/*** writing the value onto the HEAD**/
s->HEAD++;
// return 0;
}
}
void Buffer_init()
{
	d = (char *) malloc(15);
	return d;
}
void release(char *s)
{
	free(s);
}





