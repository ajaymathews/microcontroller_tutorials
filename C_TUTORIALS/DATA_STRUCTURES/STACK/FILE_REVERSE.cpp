#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int *data;   // to allocate the dynamic array, pointer need to hold the base address, or consider it holds the memory.
	int top;
	int size;   // taking the size as an stack variable to store the size each stack member takes
}stack;         // stak is the variable created using the structure, since typedef is used, stack is the new datatype instead of struct.

int init(stack *sp, int max)
{	
	sp->top=-1;    // initializing as the each stack starts with a -1 as its first index ,so that whwen it hits the -1, we could print an underflow									 
	sp->data=(int*)malloc(sizeof(int) * max);	 // malloc has only one parameter the size needed to alloctae
 											// this will allocate space for the maximum number of integers, since data is in int values	
	if(sp->data==NULL)
	{
		printf("THE ALLOCATION OF MEMORY FAILED");
		exit(1);
	}																				

				  
	(sp->size)=max;   // storing the maximum number of size for each stack memeber
	return;
}

int push(stack *sp,int pushvalue)  // in the push function there are 2 values one is the adress of the current stack(s1 or s2 or s3),
{	
int extra;							// and the value to be pushed to the stack
	if((sp->top)==(sp->size))          // always check for overflow for a push
	{
		printf("ALLOCATED STACK OVERFLOWN, PLEASE SPECIFY NUMBER OF EXTRA VALUES NEEDED:");
		scanf("%d",&extra);
		sp->data =realloc(sp->data,sizeof(int)* (sp->size+extra));
		sp->size=sp->size+extra;
	//	printf("the total size allocated is %d",sizeof(sp->data));
	}
	sp->top++;                 // always note that data is assigned only after the index is incremented
    sp->data[sp->top]=pushvalue; //finding the last index using the 'sp->top' 	
}
int pop(stack *sp)  // it returns an integer , which is the poped value from the stack
{
	if(sp->top==-1)    // always first check whether the stack is undrflow before pop
	{
		printf("STACK UNDERFLOW"); 
		return(-9999);   // just to show that the pop hits an error 
	}
	int popvalue;

	popvalue=sp->data[sp->top];  // sp.top shows the index which is the last position of data index
	                            // we then find the last value using this index location instead of '.' for structure in pointer '->' is used 
    sp->top--;                     // at last when the last value is poped thus index is reduced by one
	return popvalue;   //returning the poped value to the function
}
void delloc(stack * sp)
{
	free(sp->data);
}

int main()
{
	stack s1;
	int ch,pushval,max,popvalue;
	printf("ENTER THE MAXIMUM NUMBER OF DATA TO BE PUSHED:");
	scanf("%d",&max);
	init(&s1,max);
		
	printf("1.PUSH\n");
	printf("2.POP\n");
	printf("3.EXIT\n");
	while(1)
	{
			printf("YOUR CHOICE PEASE:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					printf("ENTER THE VALUE TO BE PUSHED:");
					scanf("%d",&pushval);
					push(&s1,pushval);
					break;
				case 2:
					popvalue=pop(&s1);
					if(popvalue==-9999)
					{
					return 1;
					}
					printf("the 'pop'ed value from stack is %d \n \r",popvalue);
					break;
				case 3:
					exit(0);
					delloc(&s1);
			}
	}
	return 0;		
}
