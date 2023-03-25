#include<stdio.h>
#include<time.h>
void main()
{	int count=0,rand_num;
	srand((int)time(&rand_num));//each random number generated beacuse of this function otherwise
	                        //the random numbers be same in every case
	while(count<20)
	{
	//printf(":%d\n",rand()); //rand() genrtes large numbers
	rand_num=rand()%9;
	printf("%d\n",rand_num);
	count++;
	}
}
