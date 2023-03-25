#include<stdio.h>
struct node
{
	int data;
	struct node *nxt_adds; //to store next node adress
	
};
struct node *start=NULL,*temp_start;


void create()
{
	int val;
	struct node *replc_ptr,*new_node;
	printf("\nWarning: Entering -1 will terminate node..!\n");
	printf("List:");
	scanf("%d",&val);
	
	while(val!=-1)//entering a -1 will terminate the list insertion
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=val;
		if(start==NULL) //only to identify it is the first creation of node, 
		{				//thus checking with null, after that changing start
		
			new_node->nxt_adds=NULL;//the newst node adress is assigned start(which may be null or
								   // previous node adress)
			start=new_node;//the current node adress is stored to start,to be used to assign 
						  //these adress to next node
			temp_start=start;
		}
		else
		{
			replc_ptr=temp_start; //replc_ptr is used to adress the previous node adress stored
										//in temp_start,and that by replace the adds of the previous node 
									   //with adress of new node
			replc_ptr->nxt_adds=new_node;//changing the previous nodde adress with current nodes adress
			
			new_node->nxt_adds=NULL;
			temp_start=new_node;
		}
		printf(":");
		scanf("%d",&val);
	}
}

/*To inserta a node to the start of the list*/
void insert_begin()
{
	struct node *new_node,*replc_ptr,*temp_start;
	int count=0,val;
	printf("\nWarning: Entering -1 will terminate node..!\n");
	printf("List:");
	scanf("%d",&val);
	while(val!=-1)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		if(count==0)
		{
			new_node->data=val;
			new_node->nxt_adds=NULL;//adress must store next nodes adress,thus by default set it to NULL
			temp_start=start;//storing the previous start adress to temp_start
			start=new_node;//from now on the starting adress is this new created node at begining
			replc_ptr=new_node;
			count=1;
		}
		else
		{
			replc_ptr->nxt_adds=new_node;
			new_node->data=val;
			new_node->nxt_adds=NULL;
			replc_ptr=new_node;
		}
		printf(":");
		scanf("%d",&val);
		
	}
	new_node->nxt_adds=temp_start; //assign the adress part of last created node to 
								  //previous start adress stred in temp_start
}

/*inserting a node to the given position in linked list*/
void insert_pos(int pos)
{
	struct node *ptr,*temp_ptr,*new_node,*replc_ptr;
	int count=1,first=0,val;
	ptr=start;	
	
	while(count!=pos) //this is used to count the position , with each node passes, count is incremented
	{
		ptr=ptr->nxt_adds;
		count++;	
    }
    temp_ptr=ptr->nxt_adds; //the last ptr must be always the matched pos,bcz then only while loop exits,
                           //we are assigning the next node after the matched to temp, bcz thus nodes adress 
                          //must be the last created nodes adress part
    printf("\nWarning: Entering -1 will terminate node..!\n");
	printf("List:");
	scanf("%d",&val);
	while(val!=-1)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		if(first==0) //to ensure this 'if' part executes only one time
		{
			new_node->data=val;
			new_node->nxt_adds=NULL;
			ptr->nxt_adds=new_node;//the current matched position node adress part is changed 
								  //with newly created node adress
			replc_ptr=new_node;   //storing temporarly, to assign adress part to coming node.
			first=1;             //to ensure this if part executes only one time
		}
		else
		{
			replc_ptr->nxt_adds=new_node;
			new_node->data=val;
			new_node->nxt_adds=NULL;
			replc_ptr=new_node;
		}
		printf(":");
		scanf("%d",&val);
			
	}
    new_node->nxt_adds=temp_ptr;// storing the adress of the node to newly created node
	
}
void print()
{
	struct node *ptr;
	ptr=start;	
	printf("\n");
	printf("Data:");
	while(ptr->nxt_adds!=NULL)
	{
		printf("%d\t",ptr->data);	
		ptr=ptr->nxt_adds;
    }
    printf("%d",ptr->data);
	printf("\n");	
    //printf("\n Node Reached End\n");
}

/*to delete a node from the start */
void delete_begin()
{
	struct node *ptr;
	start=start->nxt_adds;//the stating adress is shifted to next node		
}
void delete_pos(int pos)
{
	int count=1;
	struct node *ptr,*aft_ptr,*pre_ptr;
	ptr=start;	
	
	while(count!=pos)
	{
		pre_ptr=ptr;//storng the previous nodes adress before the hit, so this node can be connected to
				   //the node after the hit, so as the hitted node is eliminated
		ptr=ptr->nxt_adds;
		count++;	
    }
    aft_ptr=ptr->nxt_adds;//finding the node after the hit
    pre_ptr->nxt_adds=aft_ptr;//assigning the previous node before hits adress part with the node 
    					//aftre hits adress
    					free(ptr);
}

void delete_end()
{
	struct node *ptr,*del;
	ptr=start;	
	while(ptr->nxt_adds!=NULL)
	{	
		del=ptr;//to store the adress of previous pointer before null
		ptr=ptr->nxt_adds;//checking till reach end
    }
    free(ptr);
    del->nxt_adds=NULL;	//assigning the adress part of second last node with null;	
}
void free_all()
{
	struct node *ptr,*next_ptr;
	ptr=start;	
	while(ptr->nxt_adds!=NULL)
	{
		next_ptr=ptr;
		free(ptr);	
		ptr=next_ptr->nxt_adds;
    }
    printf("%d",ptr->data);
    free(ptr);
    free(next_ptr);
	printf("\n");	
}
void main()
{	
	int ch,ch1,pos;
	
	while(1)
	
	{
	lab:
	printf(" 1.Insert a Node\n");
	printf(" 2.Print List\n");
	printf(" 3.Delete a Node\n");
	printf(" 4.Exit\n");
	printf("   Enter Your Choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		/*options to insert node in diff methods*/
		case 1: printf("\t1.Create\n");
				printf("\t2.To the Begining\n");
				printf("\t3.To a given position\n");
				printf("\t4.To the End\n");
				printf("  \tEnter Your Choice:");
				
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
					printf("  \tEnter the position to insert Node");
					scanf("%d",&pos);
					insert_pos(pos);
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
				
				
		case 2: printf(" \tPrinting List\n");
				print();
				break;
				
		/*operations to delete node in diff methods*/		
		case 3:	printf(" \t1.From the Begining\n");
				printf(" \t2.From a given position\n");
				printf(" \t3.From the end\n");
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
					delete_pos(pos);	
				}
				else if(ch1==3)
				{
					delete_end();
				}
				break;
				
		case 4: free_all();
				exit(0);
		
	}
}
}
