                         //Inserting Deletion at the desired location 
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
	
	struct node *start = NULL;               //initialzing start as NULL
	struct node *new_node,*sttart,*ptr,*st; //new node for storing the address
	
	long int i=0,j=0,s=0,n=0;
	int r,temp,l,dlt=0;
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
   	printf("\n\nEnter the location of deletion :\n");
    scanf("%d",&l);	       
	ptr=st;
	printf("\n\n");
		                         //Code for  deletion at a location  
	while(ptr!=NULL)
	  {
	   //printf("\n in while");
	   dlt++;
	  
	    if(dlt==(l-1))
	      {//printf("\nfirst if\n");
		   sttart=ptr;
		  }
	    if(dlt==l)
	      {//printf("\nsecond if\n");
		   sttart->next=ptr->next;
	       free(ptr);                      //erasing address 
	     // ptr->next=sttart->next;
	       break;
	      }
	   ptr=ptr->next;
	  }
	//printf("exited while\n");
	printf("\nThe roll numbers after deletion are :\n");
    while(start!=NULL)
	  {
	   printf("%d ",start->roll_num);
	   start=start->next;
     }
	 
}






	





