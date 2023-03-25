//value is inserted into the rear(back) and deleted from the front
//#define size 10
#include<stdio.h>>
typedef struct
{
	int size;
	int *data;
	int rear;
	int front;
}queue;         // FROM NOW ON QUEUE VARIABLE IS USED INSTEAD OF STRUCT

void init(queue *qp,int max)
{
	qp->data=(int*)malloc(sizeof(int)*max);     // ALLOCATING SPACE FOR THE QUEUE
	qp->size=max;
	qp->front=0;
	qp->rear=0;
	
	return ;
}
int enqueue(queue *qp,int val)
{
	char ch;
	int extra;
	if(((qp->rear+1)%qp->size)==qp->front)    // checking if the rtating rear location is at the position of front
	{
	printf("QUEUE OVERFLOW.....\n\n");
	printf("DO YOU WANT MORE SPACE\n 1.YES(Y) \n 2.NO(N):");
	scanf(" %c",&ch);
	if(ch=='Y')
	{
		printf(" PLEASE SPECIFY NUMBER OF EXTRA VALUES NEEDED:");
		scanf("%d",&extra);
		qp->data =realloc(qp->data,sizeof(int)* (qp->size+extra));   //alocating extra memory
		qp->size=qp->size+extra;	   
	}
	return 1;
	}
	qp->data[((qp->rear+1)%qp->size)]=val;   // this is a method to automatically rotate through the queue upto their max size,
											//since ' % size' is used,then return to starting one and continues till it hits equal to front
	qp->rear=((qp->rear+1)%qp->size);
	printf("%d IS INSERTED \n",val);
	printf("REAR:%d \t FRONT:%d \n\n",qp->rear,qp->front);
}

int dequeue(queue *qp)
{
	int val;
	if(qp->front==qp->rear)
	{
		printf("QUEUE UNDERFLOW....!\n");
		return(-99999);
	}
	qp->front=((qp->front+1)%qp->size);  // front is also reducing and again starts from zero , till it hits rear;
	val=qp->data[qp->front];
	printf("REAR:%d \t FRONT:%d \n\n",qp->rear,qp->front);
	return val;
}

int main()
{
	int choice,max,num,val;
	printf("ENTER THE SIZE OF QUEUE:");
	scanf("%d",&max);
	max++;
	queue q1;
	init(&q1,max);
	while(1)
	{
	
	printf("\n CHOOSE YOUR OPTION \n 1.ENQUEUE \n 2.DEQUEUE \n 3.EXIT\n:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("ENTER THE NUMBER TO BE INSERTED:");
				scanf("%d",&num);
				enqueue(&q1,num);
				break;
		case 2:val=dequeue(&q1);
				if(val>0)
				{
				printf("THE DEQUEUEDE VALUE IS %d \n \n",val);
				}
				break;
				
		case 3: printf("EXITING ...\n");
				exit(0);
	}
    }	
}
