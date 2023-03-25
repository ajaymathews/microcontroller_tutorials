#include<stdio.h>
void main()
{
int a[10][10],i,j;
int *p=a;

for(i=0;i<10;i++)
{
	for(j=0;j<10;j++)
	{
		printf("a[%d][%d] => %d : %d\n",i,j,&a[i][j],(p)+(i*10)+j);
	}	
}
}
