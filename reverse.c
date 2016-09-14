char reverse_string(char * str, int length)
{
int i,j;
char b;
for(i=length,j=1;i>=length/2,j<=length/2;i--,j++)
{
b=*str;
*str=*(str+i-j);
*(str+i-j)=b;
str++;
}
}
