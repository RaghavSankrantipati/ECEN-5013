#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include"data.h"

void main()
{
int8_t *a;
int32_t b,c,d;
char string1[3]={8,9,1};
char string2[3]={56,54,53};
uint8_t e[100]={25,45,24,56,74,76,8,2,1};
int length=4;
int data1=0x12345678;
int data=0x87654321;
int data2=891;
a= my_itoa(string1, data2, 10);
b= my_atoi(string2, 3);
dump_memory(e,length);
c= big_to_little(data);
d=little_to_big(data1);
}

