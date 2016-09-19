#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<memory.h>

int project_1_report()
{
uint8_t array[32], *aptr_1, *aptr_2, *aptr_3;
int8_t p,q,r,s;

aptr_1=&array[0];
aptr_2=&array[8];
aptr_3=&array[16];
for(int i=0; i<16; i++)
{
*(aptr_1+i)=i+31;
}
p=my_memzero(aptr_3, 16);
q=my_memmove(aptr_1,aptr_3,8);
r=my_memmove(aptr_2,aptr_1,16);
s=my_reverse(aptr_1,32);

printf("modified array \n");
for(int i=0; i<32; i++)
{
printf("%d \n", array[i]);
}
}
