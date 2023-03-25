#include<stdio.h>
#include<stdlib.h>
#define size 20
typedef struct{
	char data[size];
	int top;
}stack;         // stak is the variable created using the structure, since typedef is used, stack is the new datatype instead of struct.

int init(stack *sp)
{
	sp->top=-1;    // initializing as the each stack starts with a -1 as its first index
				  // so that whwen it hits the -1, we could print an underflow
}

int push(stack *sp,char pushvalue)  // in the push function there are 2 values one is the adress of the current stack(s1 or s2 or s3),
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
char pop(stack *sp)  // it returns an integer , which is the poped value from the stack
{
		if(sp->top==-1)    // always first check whether the stack is undrflow before pop
	{
		printf("stack underflow"); 
		return(-9999);   // just to show that the pop hits an error 
	}
	char popvalue;

	popvalue=sp->data[sp->top];  // sp.top shows the index which is the last position of data index
	                            // we then find the last value using this index location instead of '.' for structure in pointer '->' is used 
    sp->top--;                     // at last when the last value is poped thus index is reduced by one
	return popvalue;   //returning the poped value to the function
}
int txtrev(char source[],char dest[],stack *sp)
{
	char redata;
	FILE *fps,*fpd;    // file pointer declared for reading from sourse and writing to destination
	fps=fopen(source,"r");
	if(fps==NULL)
	{
		printf("error in reading file from source");
	}
	fpd=fopen(dest,"w");
	if(fpd==NULL)
	{
		printf("error in writing file to destination");
	}
	redata=fgetc(fps);
	while(fps!=EOF)
	{
		push(sp,redata);
		redata=fgetc(fps);
	}
	while(sp->top!=-1)
	{
		fputc(pop(sp),fpd);
	}
	
}

int main()
{	
	
	stack s1;
	init(&s1);     //initializing each stack memeber with a -1 on the top
	txtrev("C:\Users\AJAY\Documents\C_PGMS\TUTORIAL\DATA_STRUCTURES\STACK\source.txt","C:\Users\AJAY\Documents\C_PGMS\TUTORIAL\DATA_STRUCTURES\STACK\dest.txt",&s1);
    return 0;	
	
}
