#include<stdio.h>
struct node
{
	int data;
	struct node *nxt_adds; //to store next node adress
	int pos;
};
struct node *start=NULL,*temp_start;
int pos_count=0;

void create()
{
	int val;
	
	struct node *replc_ptr,*new_node;
	printf("Warning: Entering -1 will terminate node..!\n\n");
	printf("List:");
	scanf("%d",&val);
	while(val!=-1)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=val;
		new_node->pos=pos_count;
		pos_count++;
		if(start==NULL)
		{
			new_node->nxt_adds=NULL;//the newst node adress is assigned start(which may be null or previous node adress)   -----.
			start=new_node;//the current node adress is stored to start,to be used to assign these adress to next node
			temp_start=start;
		}
		else
		{
			replc_ptr=temp_start; //replc_ptr is used to adress the previous node adress stored
										//in start,and that by replace the adds of the previous node 
									   //with adress of new node
			replc_ptr->nxt_adds=new_node;
			
			new_node->nxt_adds=NULL;
			temp_start=new_node;
		}
		printf(":");
		scanf("%d",&val);
		
	}
}

void insert_begin()
{
	struct node *new_node,*replc_ptr,*temp_start;
	int count=0,val;
	printf("Warning: Entering -1 will terminate node..!\n\n");
	printf("List:");
	scanf("%d",&val);
	while(val!=-1)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		if(count==0)
		{
		new_node->data=val;
		new_node->nxt_adds=NULL;
		temp_start=start;
		start=new_node;
		replc_ptr=new_node;
		count=1;
		}
		else
		{
		replc_ptr->nxt_adds=new_node;
		new_node->data=val;
		new_node->nxt_adds=NULL;
		}
		scanf("%d",&val);
		
	}
	new_node->nxt_adds=temp_start;
}
void print()
{
	struct node *ptr;
	ptr=start;	
	printf("Pos:Data:");
	while(ptr->nxt_adds!=NULL)
	{
	printf("%d:%d\t",ptr->pos,ptr->data);	
	ptr=ptr->nxt_adds;
    }
    printf("%d:%d\t",ptr->pos,ptr->data);		
    printf("\n Node Reached End\n");
}
void delete_begin()
{
	struct node *ptr;
	start=start->nxt_adds;		
}

void delete_end()
{
	struct node *ptr,*del;
	ptr=start;	
	while(ptr->nxt_adds!=NULL)
	{	
	del=ptr;
	ptr=ptr->nxt_adds;
    }
    del->nxt_adds=NULL;		
}
void main()
{	
	int ch,ch1,pos;
	
	while(1)
	
	{
	lab:
	printf("\t1.Insert a Node into List\n");
	printf("\t2.Print Current Node\n");
	printf("\t3.Delete a Node\n");
	printf("\t4.Exit\n");
	printf("\tEnter Your Choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("\t\t1.Creating a List\n");
				printf("\t\t2.Inserting to the Begining of a List\n");
				printf("\t\t3.Inserting to a given position of a List\n");
				printf("\t\t4.Inserting to the end of a List\n");
				printf("\t\t5.Back\n");
				printf(":");
				
				scanf("%d",&ch1);
				if(ch1==1)
				{
					create();
				}
				else if(ch1==2)
				{
					insert_begin();
				}
				else if(ch1==3)
				{
					printf("\n\t\t\tEnter the position to insert Node");
					scanf("%d",&pos);
					//insert_pos(pos);
				}
				else if(ch1==4)
				{
					create();
				}
				else
				{
					goto lab;
				}
				break;
		case 2: printf("\t\tPrinting Current Values\n");
				print();
				break;
		case 3:	printf("\t\t1.Delete from the Begining of a List\n");
				printf("\t\t2.Delete from a given position of a List\n");
				printf("\t\t3.Delete from the end of a List\n");
				printf(":");
				scanf("%d",&ch1);
				if(ch1==1)
				{
					delete_begin();
				}
				else if(ch1==2)
				{
					printf("\nEnter the position to delete Node");
					scanf("%d",&pos);
					//delete_pos();	
				}
				else if(ch1==3)
				{
					delete_end();
				}
				break;
				
		case 4: exit(0);
		
	}
}
}
