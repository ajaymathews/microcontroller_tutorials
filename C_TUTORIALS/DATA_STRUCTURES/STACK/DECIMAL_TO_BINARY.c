#include<stdio.h>
#define size 20
typedef struct{
	int data[size];
	int top;
}stack;         // stak is the variable created using the structure, since typedef is used, stack is the new datatype instead of struct.

int init(stack *sp)
{
	sp->top=-1;    // initializing as the each stack starts with a -1 as its first index
				  // so that whwen it hits the -1, we could print an underflow
}

int push(stack *sp,int pushvalue)  // in the push function there are 2 values one is the adress of the current stack(s1 or s2 or s3),
{								// and the value to be pushed to the stack
	if((sp->top)==(size) )          // always check for overflow for a push
	{
		printf("stack overflow");
		return -1;
	}
	sp->top++;                 // always note that data is assigned only after the index is incremented
    sp->data[sp->top]= (pushvalue); //finding the last index using the 'sp->top' 
							   //which is the incrementing value for the current stack variable,and pushing data to the data field in the cureent index  
return 1;	
}
int pop(stack *sp)  // it returns an integer , which is the poped value from the stack
{
		if(sp->top==-1)    // always first check whether the stack is undrflow before pop
	{
		printf("stack underflow"); 
		return(-9999);   // just to show that the pop hits an error 
	}
	int popvalue;

	popvalue=sp->data[sp->top];  // sp.top shows the index which is the last position of data index
	                            // we then find the last value using this index location instead of '.' for structure in pointer '->' is used 
    sp->top--;                     // at last when the last value is poped thus index is reduced by one
	return popvalue;   //returning the poped value to the function
}
int getbinary(stack *sp,int dec)
{	const base=2;
	int rem;
	while(dec!=0)
	{
		rem=dec%base;
	    push(sp,rem);
		dec=dec/base;	
	}
	while(sp->top!=-1)
	{
		printf("%d",pop(sp));		
	}
	return 1;
}

int main()
{	
	int dec,bin;
	stack s1;
	init(&s1);     //initializing each stack memeber with a -1 on the top
	printf("enter the decimal value:");
	scanf("%d",&dec);
	bin=getbinary(&s1,dec);
    return 0;	
	
}
