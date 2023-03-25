#include<stdio.h>
#include<stdlib.h>
struct  node
	{
		int data;
		struct node *next;
	};

void print(struct node *n) 
{ 
  while (n != NULL) 
  { 
     printf(" %d ", n->data); 
     n = n->next; 
  } 
} 

int main()
{
	struct node* rollnumber=NULL;
	struct node* name=NULL;

name=(struct node*)malloc(sizeof(struct node*));	
rollnumber=(struct node*)malloc(sizeof(struct node*));

rollnumber->data=7;
rollnumber->next=name;
name->data=54;
name->next=NULL;
print(rollnumber);	
return 0;
}
