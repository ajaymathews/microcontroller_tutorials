#include<stdio.h>
#include<conio.h>
int main()
{
	struct node
	{
	  int data;
	  struct node *next;	
	};
	struct node *start=NULL;
	struct node *student(struct node*);
	start=student(start);
}

struct node (*student)(struct node *start)
{
	struct node *new_node;
	int rollnum;
	char name[50];
	
	//printf("Enter the name\n");
	//scanf("%s",name);
	printf("Enter the roll number\n");
	scanf("%d",rollnum);
	
	new_node=(struct node*)malloc(sizeof(struct node*));
	new_node->data=rollnum;
	if(start==NULL)
	{
	new_node -> next=NULL;
	start=new_node;
    }
	else
	{
	new_node->next=start;	
	start=new_node;
	}
	printf("Name= %s",name);
	printf("%d",rollnum);

    return start;
}
	
	
	

