#include "MKL25Z4.h"
#include<stdint.h>
#include<string.h>
#include"log.h"
#include<stdlib.h>

void start();
void TPM2_Setup();
int stop();
typedef struct
{
uint8_t* HEAD;
uint8_t* TAIL;
uint8_t* Buffer;
}structure;

//void Buffer_init(int l);
//int8_t my_reverse(uint8_t * src, uint8_t * dst, uint32_t length);
//void my_memmove(uint8_t * src, uint8_t * dst, uint32_t length);
/*uint8_t add_data(structure *s,uint8_t Value,uint8_t length);
uint8_t Buffer_Full(structure *s,uint8_t length);
uint8_t remove_data(structure *s);
uint8_t Buffer_Empty(structure *s);*/
void my_ftoa(float n, char *res, int afterpoint);
int intToStr(int x, char str[], int d);
void reverse(char *str, int len);
int32_t my_atoi(int8_t *str);
//int32_t my_atoi(int8_t *str);

void TPM2_Setup()
{
//	MCG_BASE_PTR->C1 = MCG_C1_IREFS_MASK | MCG_C1_IRCLKEN_MASK;
//	MCG_BASE_PTR->C2 = MCG_C2_IRCS_MASK;
	SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM2_MASK;
	SIM_BASE_PTR->SOPT2 |= SIM_SOPT2_TPMSRC(1);
	TPM2_BASE_PTR->SC = TPM_SC_CMOD(1) | TPM_SC_PS(0);
	TPM2_BASE_PTR->MOD = 32000;
	TPM2_BASE_PTR->CONTROLS[0].CnSC=TPM_CnSC_MSB_MASK|TPM_CnSC_ELSA_MASK;
	TPM2_BASE_PTR->CONTROLS[0].CnV=TPM2_BASE_PTR->MOD;
}

void start()
{
	TPM2_Setup();
}

int stop()
{
	TPM2_BASE_PTR->SC = TPM_SC_CMOD(0);
	int count=TPM2_CNT;
	int x=count/21;
	return x;
}

void main()
{
	/*char d[]="ghjsag";
	structure a;
	a.Buffer=d;
	a.HEAD=d;
	a.TAIL=d;
	//int a[1000],b[1000];

	/*start();
 memset(a,0,1000);
	//memset(a,b,1000);
int time1=stop();
char str[]="Inbuilt time for zero 100 in us:";
int l=strlen(str);
LOG1(str,l,time1,8);
*/
	//char* str=(char *)malloc(1000);
	//*add_data(&a,10,13);*/
	//char string2[3]={56,57,58};
	float param=123.44;
	char par[10];
start();
my_ftoa(param,par,3);
//int b= my_atoi(string2);
//free(str);
//char c[]="This is log for more values";
//LOG(c,strlen(c));
//remove_data(&a);

int time2=stop();
char str1[]="time for ftoa in us :";
int l1=strlen(str1);
LOG1(str1,l1,time2,8);
//	start();
//    memmove(a,b,100);
//	int time2=stop();
//	start();
//    memmove(a,b,1000);
//	int time3=stop();
//
//	start();
//  my_memmove(a,b,10);
//	int time4=stop();
//	start();
//    my_memmove(a,b,100);
//	int time5=stop();
//	start();
//    my_memmove(a,b,1000);
//	int time6=stop();

	int y=0;


}
/*void Buffer_init(int l)
{
	d = (char *) malloc(l);
	//return d;
}*/
/*void my_memmove(uint8_t * src, uint8_t * dst, uint32_t length)
{
int i;
if(src==dst)
{

//return 0;
}


else if(dst<src+length)
{
if(dst<src)
{
for( i=0;i<length;i++)
{
*(dst+i)=*(src+i);
//printf("%d \n", *(dst+i));
}
}
else if(src<dst)
{
for( i=length-1;i>=0;i--)
{
*(dst+i)=*(src+i);
//printf("%d \n", *(dst+i));
}
}

//return 1;

}
else
{
for( i=0;i<length;i++)
{
*(dst+i)=*(src+i);
//printf("%d \n", *(dst+i));
}

//return 1;
}
}*/
/*uint8_t add_data(structure *s,uint8_t Value,uint8_t length)
{
/*** check before writing the values whether the buffer is full****/
/*
if(Buffer_Full(s,length))
{
//printf("Buffer is full");
	char s[]="Buffer is full";
	//log(s,strlen(s));
return -1;
}
else
{
*s->HEAD= Value;/*** writing the value onto the HEAD**/
// s->HEAD++;
//return 0;
//}
//}*/
/*
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
uint8_t Buffer_Empty(structure *s)
{
if((s->HEAD)==(s->TAIL))
return 1;
else
return 0;
}
/**** Buffer Remove*****/
/*uint8_t remove_data(structure *s)
{
if(Buffer_Empty(s))
{
//printf("Buffer is Empty");
	char s[]="Buffer is Empty";
	//log(s,strlen(s));
return -1;
}
else
{
s->TAIL++;
return 0;
}
}*/
/*int8_t *my_itoa(int8_t *str,int32_t data,int32_t base)
{
    int32_t rem;
    int num=data;
    int8_t i=0;
    int8_t beg,end;
    char temp;
    if(data<0)
    {
    data=-data;
    }
    else {data=data;}
    while(data!=0)
    {
        rem=data%base;
        if(rem>9)
        {
            *(str+i)=(rem-10)+'a';
        }
        else
        {
        *(str+i)=rem+'0';
        }
        data=data/base;
        i++;
    }

    if(base==10 && num<0)
    {
        *(str+i)='-';
        i++;
    }

    //to reverse the string
    for(beg=0,end=i-1;beg<end;beg++,end--)
    {
        temp=*(str+beg);
        *(str+beg)=*(str+end);
        *(str+end)=temp;
    }

    *(str+i)='\0';
    i++;
    return str;
}
*/
int32_t my_atoi(int8_t *str)
{
	if(str!=NULL)
	{
		while(*str!='\0')
		{
		if(*str>='0' && *str<='9' || *str=='-')
		{
			//printf("%d",*str);
		}
		else return 0;
		str++;
	}
	}
	*str=0;
}

void my_ftoa(float n, char *res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0)
    {
        res[i] = '.';  // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter is needed
        // to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x)
    {
        str[i++] = (x%10) + '0';
        x = x/10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}
void reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}
