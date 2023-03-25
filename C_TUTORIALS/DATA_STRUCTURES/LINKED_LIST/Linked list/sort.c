#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	
	struct node
	{
	 int roll_num;
     char name;
	 struct node *next;         //internal reference pointer
	};
	
	struct node *start = NULL; //initialzing start as NULL
	struct node *new_node; //for storing the address
	struct node *st;
	struct node *ptr1,*ptr2,*ptr;
	long int i=0,j=0,s=0,n=0;
	int r,temp;
    char a;	
    printf("Enter the number of students\n");
    scanf("%d",&n);
  
	for(i=0;i<n;i++)
	{   
	    printf("Enter the roll number\n");
	    scanf("%d",&r);
	    printf("Enter the name:\n");
	    scanf(" %c",&a);
		new_node=(struct node*)malloc(sizeof(struct node*));//getting address of the node
		new_node->roll_num=r;
	    new_node->name=a;

	//	new_node->name=a;
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

	for(s=0;s<n;s++)
		{
		  //printf("loop1");
		  if(s==0)
		   {//printf("i=0");
			ptr1=start;
		    ptr2=start->next;
		   }
		  else
	   	   {
		    ptr1=ptr1->next;
		    ptr2=start;
		    //printf("i>0");
	       }
			for(j=0;j<n-1;j++)
			  {//printf("loop2 %d",n);
			
			   if(ptr2->roll_num>ptr1->roll_num)
			    { 
				  temp=ptr1->roll_num;
			      ptr1->roll_num=ptr2->roll_num;
			      ptr2->roll_num=temp;
			    } 
		          ptr2=ptr2->next;
		      }
	    }
	printf("sorted");    	       
	ptr=st;
	printf("\n\n");
	printf("The sorted roll numbers are :\n");
	
	while(ptr!=NULL)
	  {
	   printf("%d",ptr->roll_num);
	   //printf(" %c",ptr->name);
	   ptr=ptr->next;
	  }

}






	





