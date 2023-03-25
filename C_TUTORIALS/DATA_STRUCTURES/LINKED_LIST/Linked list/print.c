#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;         //internal reference pointer
};
int main()
{
	struct node *start = NULL; //initialzing start as NULL
	struct node *new_node;    //declaring pointer for mmry alloc
	
	long int i=0,n=0;
	int a;
	printf("Enter the total number of numbers that you want to display\n");
	scanf("%d",&n);
	printf("Enter the numbers to display\n");
	
	for(i=0;i<n;i++)
	{  
	    scanf("%d",&a);
		new_node=(struct node*)malloc(sizeof(struct node*)); //getting address of the node
		new_node->data=a;
		
			if(start==NULL)
			{
			new_node->next=NULL;
			start=new_node;
			}
			else
			{
			new_node->next=start;
			start=new_node;
			}
			      
	}
struct node *ptr;
ptr=start;
printf("\n");
while(ptr!=NULL)
{printf(" %d",ptr->data);
ptr=ptr->next;
}

}


