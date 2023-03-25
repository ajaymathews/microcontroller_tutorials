#include<stdio.h>
void main()
{
	int i,j=0;
	char nam[10]="hello\b";
	
	for(i=0;i<=100;i++)
	{
		printf("%d:",j);
		j=(j++);//in this case upon assigning j=j++, the value should be incremnted first
		        //for that,j is taken to temp and then incremented, but it is a postincremnt operation, 
		        //thus assigning is done first which assign the previous value to j //i think 
		printf(":%d\n",j);
		
	}

	printf("%d\n",j);
	
	printf("%s",nam);	
	printf("%s\n",nam);		
}
