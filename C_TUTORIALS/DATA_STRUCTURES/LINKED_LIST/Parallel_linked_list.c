#include<stdio.h>
struct node{
	int data;
	struct node* addr;
};
struct node* start[10];
struct node* create_node(struct node* pre,int n){
	struct node* new;
	int val=0;
	if(pre==-1){
		printf("    Sorry, List already joined with other\n");
		return -1;
	}
	printf("    Enter the data (-1 will terminate the list)\n    :");
	scanf("%d",&val);
	while(val!=-1){
		new = malloc(sizeof(struct node));
		new->addr=NULL;
		new->data=val;
		if(pre==NULL){
			start[n]=new;
		}
		else{
			pre->addr=new;
		}
		pre=new; //this is needed since the updation of pre is in the loop
		printf("    :");
		scanf("%d",&val);
	}
	return new;
}
void print_list(int n){
	int count=0,limit=0;
	struct node* temp;
	while(count<=n){
		temp=start[n];
		printf("    List %d: ",n);
		if(start[n]==NULL){
			printf("List Empty");
			goto x;
		}
		while(temp->addr!=NULL&&limit<20){
			printf("%d---",temp->data);
			temp=temp->addr;
			limit++;
		}
		printf("%d---",temp->data);
		x:
		n--;
		printf("\n");
	}
}
int find_length(int n){
	struct node* temp=start[n];
	int len=0;
	while(temp->addr!=NULL){
		len++;
		temp=temp->addr;
	}
	return len+1;
}
struct node* goto_node(struct node* start, int n){
	struct node* temp=start;
	int count=0;
	n--;
	while(count!=n){
		temp=temp->addr;
		count++;
		if(temp->addr==NULL){
			printf("limit out of reach\n");
			return -1;
		}
	}
	return temp;
}
void create_joint(int n1,int n2){
	struct node* main_temp,*sec_temp;
	int pos1,pos2;
	printf("    Enter the main list position to join:");
	scanf("%d",&pos1);
	printf("    Enter the Secondary list position to attach:");
	scanf("%d",&pos2);
	main_temp=goto_node(start[n1],pos1);
	sec_temp=goto_node(start[n2],pos2);
	if(main_temp==-1||sec_temp==-1){
		return 0;
	}
	sec_temp->addr=main_temp->addr;
}
void create_loop(int n){
	struct node* temp,*last;
	int pos=0;
	printf("    Enter the starting position of the loop:");
	scanf("%d",&pos);
	temp=goto_node(start[n],pos);
	last=goto_node(start[n],find_length(n)-1);
	last->addr=temp;
}
struct node* check_loop(int n){
	struct node* temp1=start[n],*temp2=start[n];
	while(temp1->addr!=NULL&&temp2->addr!=NULL){
		temp1=temp1->addr;
		temp2=temp2->addr->addr;
		if(temp1==temp2){
			printf("    Loop is present\n");
			temp1=start[n];
			while(temp1->addr!=NULL&&temp2->addr!=NULL){
				temp1=temp1->addr;
				temp2=temp2->addr;
				if(temp1==temp2){
					return temp1;
				}
			}
		}
	}
	printf("    Loop Not present\n");
	return 0;
}
struct node* find_loop(int n){
	struct node* temp =check_loop(n);
	printf("    The loop starts at %d\n",temp->data);
	return temp;
}
int correct_loop(int n){
	struct node* t1=find_loop(n);
	struct node* t2=t1->addr;
	while(t1!=t2->addr){
		t2=t2->addr;
	}
	t2->addr=NULL;
	return 1;
}
void check_for_joint(int n1,int n2){
	int l1=find_length(n1),l2=find_length(n2),match=0,diff=0;
	struct node *t1=start[n1],*t2=start[n2],*ret_point=NULL;
	if(l1<l2){
		diff=l2-l1;
		t2=goto_node(start[n2],diff);
		t2=t2->addr;
	}
	else{
		diff=l1-l2;
		t1=goto_node(start[n1],diff);
		t1=t1->addr;
	}
	if(t1==-1||t2==-1){
		printf("Incorrect data\n");
		return -1;
	}
	while(t1->addr!=NULL||t2->addr!=NULL){
		if(t1->data==t2->data){
			match++;
		}
		t1=t1->addr;
		t2=t2->addr;
	}
	l1=l1>l2?l1:l2;
ret_point = goto_node(start[n1],l1-match);
printf("point of joint is: %d\n",ret_point->data);
}
void delete_node(int n){
	struct node* temp=start[n];
	struct node* del_ptr=NULL;
	while(temp->addr!=NULL){
		del_ptr=temp;
		temp=temp->addr;
	}
	free(temp);
	if(del_ptr==NULL){
		start[n]=NULL;
		printf("\nNodes exhausated ..!!\n");
		return 1;
	}
	else
		del_ptr->addr=NULL;
}
void main(){
struct node* pre[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
int ch,ch1,ch4,n,n1,n2,n4;
while(1){
	printf("Enter the Choice:\n1.Create List\n2.Print List\n3.Delete List\n4.Operation\n5.Exit\n:");
	scanf("%d",&ch);
	switch(ch){
		case 1:printf("  1.Create a New node\n  2.Continue with list\n  :");
			scanf("%d",&ch1);
			if(ch1==1){
				printf("    Enter the Linked list number:");
				scanf("%d",&n);
				pre[n]=create_node(pre[n],n);
			}
			else if(ch1==2){
				printf("    Enter the Linked list number:");
				scanf("%d",&n);
				pre[n]=create_node(pre[n],n);	
			}
			break;
		case 2:	printf("  Enter the Linked list number:");
				scanf("%d",&n);
				print_list(n);
			break;
		case 3: printf("  Enter the Linked list number:");
				scanf("%d",&n);
				delete_node(n);
			break;
		case 4: printf("  1.Create joint\n  2.Create loop\n  3.Check for joint\n  4.Check for loop\n  5.Correct the loop\n    :");
				scanf("%d",&ch4);
				if(ch4==1){
					printf("    Enter the main list Number:");
					scanf("%d",&n1);
					printf("    Enter the secondary list Number:");
					scanf("%d",&n2);
					pre[n2]=-1;
					create_joint(n1,n2);
				}
				else if(ch4==3){
					printf("  Enter the linked list number to check\n    List 1:");
					scanf("%d",&n1);
					printf("    List 2:");
					scanf("%d",&n2);
					check_for_joint(n1,n2);
				}
				else if(ch4==2){
					printf("  Enter the list number:");
					scanf("%d",&n1);
					create_loop(n4);
				}
				else if(ch4==4){
					printf("  Enter the list number:");
					scanf("%d",&n1);
					find_loop(n1);
				}
				else if(ch4==5){
					printf("  Enter the list number:");
					scanf("%d",&n1);
					if(correct_loop(n))
						printf("    Loop in the list is removed\n");
					else
						printf("    Loop cannot be removed\n");
				}
				break;
		case 5:printf("  Exiting...!!\n");
			exit(0);
			break;
		}			
	}
}
