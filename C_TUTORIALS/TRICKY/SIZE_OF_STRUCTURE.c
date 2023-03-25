#include<stdio.h>
void main()
{
struct xyz
{
int x;
float k;
char y;
}obj[10];

struct xyz* val1=&obj[0];
struct xyz* val2=&obj[1];
printf("using sizeof: %d\n",sizeof(obj[0]));

printf("without using sizeof:%d-%d",(val2),(val1));//only thing is that i cant - the pointer,
//if so ans will be 1,maybe the next adress location differnce is taken as 1
}
