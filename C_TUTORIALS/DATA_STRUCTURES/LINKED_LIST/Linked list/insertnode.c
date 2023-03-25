#include<stdio.h>
#include<conio.h>
struct node
{
int data;
struct node *next;               //internal reference pointer
};
void init()
{
	struct node *start = NULL;      //initialzing start as NULL
 	
}
int main()
{	

    struct node *new_node;    //for storing the address
	int num;
	printf("Enter the data\n");
	scanf("%d",&num);
	
	new_node=(struct node*)malloc(sizeof(struct node*));//allocating space thus getting address
	
    new_node->data=num;
    new_node->next=start;

    start=new_node;
    
   

}


