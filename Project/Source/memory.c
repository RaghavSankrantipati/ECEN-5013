#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "memory.h"

int8_t my_memmove(uint8_t * src, uint8_t * dst, uint32_t length)
{
int i;
if(src==dst)
{
return 0;
}


else if(dst<src+length)
{
int b[100];
for(i=0; i<length;i++)						//if destination and overlaps, a temporary array is taken and first the sorce values are stored in 									//it and later transfered to destination
{
b[i]=*(src+i);
}
for(i=0;i<length;i++)
{
*(dst+i)=b[i];
} 

return 1;

}
else
{
for( i=0;i<length;i++)
{
*(dst+i)=*(src+i);
								//values at source are directly copied into destination
}
return 1;
}
}

int8_t my_memzero(uint8_t * src, uint32_t length)
{
int i;
for( i=0;i<length;i++)
{								//all the values at source are made zero
*(src+i)=0;
}
return 1;
}



int8_t my_reverse(uint8_t * src, uint32_t length)
{
int i,j;
int a[100];
for( i=0;i<length;i++)
{
a[i]=*(src+i);

}								//source values are stored in a temporary register and they are transferred to source in reverse.
i=0;
j=length-1;
for(int i=0; i<length; i++)
{
*(src+i)=a[j];
j--;
}

return 1;
}


