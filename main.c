#include<stdio.h>
#include<string.h>
#include "hw1.h"
void main()
{
char a;
unsigned char str1[] = "This is a string";
unsigned char str2[] = "some NUMmbers12345";
unsigned char str3[] = "Does it reverse \\n\\0\\t correctly?";
printf(" Before Reverse is %s\n",str1);
reverse_string(str1, strlen(str1));
printf(" After Reverse is %s\n",str1);
printf(" Before Reverse is %s\n",str2);
reverse_string(str2, strlen(str2));
printf(" After Reverse is %s\n",str2);
printf(" Before Reverse is %s\n",str3);
reverse_string(str3, strlen(str3));
printf(" After Reverse is %s\n",str3);
}
