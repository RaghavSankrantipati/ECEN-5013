/*
 * led_config.c

 *
 *  Created on: Nov 9, 2016
 *      Author: moed4346
 */
#include <string.h>
#include "led.h"
#include "Message.h"
int str_cmp(char *s,char *d,int length)
{
	int i=0;
	while(i<length)
	{
		if(*(s+i)==*(d+i))
			i++;
		else
			return 1;
	}
	return 0;
}
void Led_config(CI_Msg *s)
{
	char str1[4],str2[4],str3[2];
									char b[]="blue";
									char r[]="red";
									char y[]="cyan";
									strncpy(str2,s->data,s->length);
		int r2=str_cmp(str2,b,(s->length-0x30));
		if(r2==0)
		{
		//time(&start_t);
		//off(mod_value);
	    Blue(32000);
		//time(&end_t);
		//diff_t = difftime(end_t, start_t);
		}
		int r1=str_cmp(str2,r,(s->length-0x30));
		if(r1==0)
		{
		//time(&start_t);
		//off(mod_value);
		Red(32000);
	    //time(&end_t);
		//diff_t = difftime(end_t, start_t);
		}
		int r3=str_cmp(str2,y,(s->length-0x30));
																																						if(r1==0)
		if(r3==0){
		//time(&start_t);
		//off(mod_value);
		cyan(32000);
		//time(&end_t);
	    //diff_t = difftime(end_t, start_t);

	     }
											/*
											if(value==2)
											{
												time(&start_t);
												off(mod_value);
												Blue(mod_value);
												time(&end_t);
												diff_t = difftime(end_t, start_t);
											}
											if(value==3)
											{
												time(&start_t);
												off(mod_value);
												Green(mod_value);
												time(&end_t);
												diff_t = difftime(end_t, start_t);
											}
											if(value==4)
											{
												off(mod_value);
												Yellow(mod_value);
											}
											if(value==5)
											{
												off(mod_value);
												violet(mod_value);
											}
											if(value==6)
											{
												off(mod_value);
												cyan(mod_value);
											}
											if(value==7)
											{
												off(mod_value);
												white(mod_value);
											}
											if(value<0||value>7)
											{
												off(mod_value);
												value=0;
											}*/
}


