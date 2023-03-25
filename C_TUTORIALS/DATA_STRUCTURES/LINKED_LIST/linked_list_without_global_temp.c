#include<stdio.h>
struct node{
	int data;
	struct node* addr;
};
struct node* start;
struct node* create_node(struct node* pre){
	struct node* new = malloc(sizeof(struct node));
	new->addr = NULL;
	if(pre==NULL){
		start=new;
	}
	else{
		pre->addr=new;
	}
	printf("Enter the Data:");
	scanf("%d",&new->data);
	return new;
}
void print_nodes(){
	struct node* temp=start;
		if(start==NULL){
			
			printf("Nodes Exhausted\n");
			return 0;
		}
	while(temp->addr!=NULL){
		printf("%d-----",temp->data);
		temp=temp->addr;
	}
	printf("%d-----",temp->data);
}
void free_nodes(){
	struct node* temp=start;
	struct node* free_ptr=NULL;
	while(temp->addr!=NULL){
		free_ptr=temp;
		temp=temp->addr;
		free(free_ptr);
	}
}
void delete_node(){
	struct node* temp=start;
	struct node* del_ptr=NULL;
	while(temp->addr!=NULL){
		del_ptr=temp;
		temp=temp->addr;
	}
	free(temp);
	if(del_ptr==NULL)
		start=NULL;
	else
		del_ptr->addr=NULL;
}

void main(){
	struct node* pre=NULL;
	int n=0;
	while(1){
	printf("\nCHOOSE YOUR OPTION\n");
	printf("1.Create Node\n2.Delete Node\n3.Print Nodes\n4.Exit\n:");
	scanf("%d",&n);
	switch(n){
		case 1:pre=create_node(pre);
			break;
		case 2:delete_node();
			break;
		case 3:print_nodes();
			break;
		case 4:free_nodes();
			exit(0);
			break;
		}	
	}
}
