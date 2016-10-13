/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MKL25Z4.h"
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "Buffer.h"
#include "log.h"
char Data[]="this is log";
int main()
{
int j=0;
uint8_t result1,result2;
structure a;
a.Buffer=Data;
a.HEAD=Data;
a.TAIL=Data;
//while(1)
//{
for(int i=0;i<strlen(Data);i++)
{
result1=add_data(&a,*(Data+i),strlen(Data));
if(result1==0)
{
//printf("Added Succesfully");
	char s[]="Added Succesfully";
log(s,strlen(s));
}
else if(result1==-1)
{
//printf("Buffer full");
	char s[]="Buffer is full";
	log(s,strlen(s));
//a.HEAD=Data;
//a.TAIL=Data;
}
}
for(int i=0;i<strlen(Data);i++)
{
result2=remove_data(&a);
if(result2==0)
{
	char s[]="Removed Succesfully";
	log(s,strlen(s));
//printf("Removed Succesfully");
}
else if(result2==-1)
{
	char s[]="Buffer empty";
	log(s,strlen(s));
	//printf("Buffer empty");
a.HEAD=Data;
a.TAIL=Data;
}
}
}
//}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
