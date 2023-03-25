                         //Inserting Deletion at the begining
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	
	struct node
	{
	 int roll_num;
     char name;
	 struct node *next;            //internal reference pointer
	};
	
	struct node *start = NULL;  //initialzing start as NULL
	struct node *new_node;     //for storing the address
	struct node *st;
	struct node *ptr1,*ptr2,*ptr;
	long int i=0,j=0,s=0,n=0;
	  int r,temp;
    char a;	
    printf("Enter the number of students\n");
    scanf("%d",&n);
    printf("Enter their roll number\n");
	for(i=0;i<n;i++)
	{   
	    scanf("%d",&r);
		new_node=(struct node*)malloc(sizeof(struct node*));//getting address of the node
		new_node->roll_num=r;
	
			if(start==NULL)
			{
			new_node->next=NULL;
			start=new_node;
			}
			else
			{
			new_node->next=start;
			start=new_node;
			st=new_node;
           }
   }
   	 	       
	ptr=st;
	printf("\n\n");
	printf("The roll numbers before deletion are :\n");
	while(ptr!=NULL)
	  {
	   printf("%d ",ptr->roll_num);
	   ptr=ptr->next;
	  }
	
	//Code for inserting deletion  at the begining  
    
    start=start->next;
    free(ptr);
    
	printf("\nThe roll numbers after deletion at the begining are :\n");
    while(start!=NULL)
	  {
	   printf("%d ",start->roll_num);
	   start=start->next;
	  }
}






	





