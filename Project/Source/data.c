#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include"data.h"

int8_t * my_itoa(int8_t *str, int32_t data, int32_t base)
{
int8_t temp = str;
int b=data,n=0;
printf("\n itoa ");
for(int i=0; b>0; i++)						//This for loop is to calculate the number of digits in the given data
{
b=b/10;						
n++;
}

if(data<0) 							//if the number is negative add 45, as ascii for'-' is 45
{							        //48 is added to integer to get ascii value
printf("45");
for(int i=0; i<n; str++)
{
*(str)= *(str)+48;
printf("%d",*(str));
i++;
}
}
else
for(int i=0; i<n; str++)
{
*(str)= *(str)+48;
printf("%d",*(str));
i++;

}
printf("\n");
return(temp);
}

int32_t my_atoi(int8_t *str,int8_t length)
{
int m=length;
printf("\n atoi ");
if(*(str)==45)							// 48 is added to integer to get ascii value
{								//if the number is 45 add - , as ascii for'-' is 45
str++;
printf("-");
for(int i=1; i<m; str++)
{
*str= *str-48;
printf("%d",*(str));
i++;
}
}
else
for(int i=0; i<m; str++)
{
*(str)= *(str)-48;
printf("%d",*(str));
i++;

}
printf("\n");
return(0);
}

void dump_memory(uint8_t *start, uint32_t length)
{

int quot, rem, temp;
char b[100];
for(int i=0; i<length; i++)
{
int j=1, k;
quot=*start;
start++;
while(!(quot==0))
{
temp=quot%16;
if(temp>9)
temp=temp+55;                                               
else
temp=temp+48;
b[j++]=temp;
quot=quot/16;
}
for(k=j-1; k>0; k--)
{
printf("%c", b[k]);
}
printf("\n");
}
}

uint32_t big_to_little(uint32_t data)
{
int i;
uint32_t a[4];
a[0]=(data& 0x000000ff)<<24 ;					//except last two bytes everything is masked and this value is shifted 24 times(bits) so le last t
a[1]=(data& 0x0000ff00)<<8;				        // byte become first
a[2]=(data& 0x00ff0000)>>8; 
a[3]=(data& 0xff000000)>>24 ;					//similarly first to last. 3 bytes become 4. and 4 become 3
data=a[3]|a[2]|a[1]|a[0];
printf("big to little output is 0x%X\n ", data);     		//all these bytes which are masked and shifted are 'or'ed.
}


uint32_t little_to_big(uint32_t data)
{
int i;								//except last two bytes everything is masked and this value is shifted 24 times(bits) so le last 
uint32_t a[4];
a[0]=(data& 0x000000ff)<<24 ;					// byte become first
a[1]=(data& 0x0000ff00)<<8;
a[2]=(data& 0x00ff0000)>>8; 					//similarly first to last. 3 bytes become 4. and 4 become 3
a[3]=(data& 0xff000000)>>24 ;					//all these bytes which are masked and shifted are 'or'ed.

data=a[3]|a[2]|a[1]|a[0];
printf("little to big output is 0x%X\n ", data);
return(0);
}

