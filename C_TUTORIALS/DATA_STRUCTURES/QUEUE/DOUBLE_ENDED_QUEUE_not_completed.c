//value is inserted into the rear(back) and deleted from the front

//#define size 10
typedef struct
{
	int size;
	int *data;
	int rear;
	int front;
}queue;

void init(queue *qp,int max)
{
	qp->data=(int*)malloc(sizeof(int)*max);
	qp->size=max;
	qp->front=0;
	qp->rear=0;
	
	return ;
}
int rearenqueue(queue *qp,int val)
{
	char ch;
	int extra;
	if(((qp->rear+1)%qp->size)==qp->front)
	{
	printf("QUEUE OVERFLOW.....\n\n");
	printf("DO YOU WANT MORE SPACE\n 1.YES(Y) \n 2.NO(N):");
	scanf("%c",&ch);
	if(ch=='Y')
	{
		printf(" PLEASE SPECIFY NUMBER OF EXTRA VALUES NEEDED:");
		scanf("%d",&extra);
		qp->data =realloc(qp->data,sizeof(int)* (qp->size+extra));
		qp->size=qp->size+extra;	
	}
	return 1;
	}
	qp->data[((qp->rear+1)%qp->size)]=val;
	qp->rear++;
	printf("%d IS INSERTED \n\n",val);
}

int frontenqueue(queue *qp,int val)
{
	char ch;
	int extra;
	if(((qp->front-1)%qp->size)==qp->rear)
	{
	printf("QUEUE OVERFLOW.....\n\n");
	printf("DO YOU WANT MORE SPACE\n 1.YES(Y) \n 2.NO(N):");
	scanf("%c",&ch);
	if(ch=='Y')
	{
		printf(" PLEASE SPECIFY NUMBER OF EXTRA VALUES NEEDED:");
		scanf("%d",&extra);
		qp->data =realloc(qp->data,sizeof(int)* (qp->size+extra));
		qp->size=qp->size+extra;	
	}
	return 1;
	}
	qp->data[((qp->front)%qp->size)]=val;
	qp->front--;
	printf("%d IS INSERTED \n\n",val);
	
}

int frontdequeue(queue *qp)
{
	int val;
	if(qp->front==qp->rear)
	{
		printf("QUEUE UNDERFLOW....!\n");
		return(-99999);
	}
	qp->front=((qp->front+1)%qp->size);
	val=qp->data[qp->front];
// 	qp->front++;
	return val;
}
int reardequeue(queue *qp)
{
	int val;
	if(qp->front==qp->rear)
	{
		printf("QUEUE UNDERFLOW....!\n");
		return(-99999);
	}
	qp->rear=((qp->rear+1)%qp->size);
	val=qp->data[qp->front];
// 	qp->front++;
	return val;
}

int main()
{
	int choice,max,num,val;
	printf("ENTER THE SIZE OF QUEUE:");
	scanf("%d",&max);
	queue q1;
	init(&q1,max);
	while(1)
	{
	
	printf("CHOOSE YOUR OPTION \n 1.ENQUEUE INTO REAR \n 2.ENQUEUE INTO FRONT \n 3.DEQUEUE FROM FRONT \n 4.DEQUEUE FROM REAR \n 5.EXIT\n:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("ENTER THE NUMBER TO BE INSERTED:");
				scanf("%d",&num);
				rearenqueue(&q1,num);
				break;
		case 2:printf("ENTER THE NUMBER TO BE INSERTED:");
				scanf("%d",&num);
				frontenqueue(&q1,num);
				break;		
		case 3:val=frontdequeue(&q1);
				if(val>0)
				{
				printf("THE DEQUEUEDE VALUE IS %d \n \n",val);
				}
				break;
		case 4:val=reardequeue(&q1);
				if(val>0)
				{
				printf("THE DEQUEUEDE VALUE IS %d \n \n",val);
				}
				break;
		case 5: printf("EXITING ...\n");
				exit(0);
	}
    }	
}
