#include<stdio.h>
/***** Ist method  ****/ 
/*
struct stud
{
	int roll;
	char name[10];
}class1;
void main()
{
class1=(struct stud){1,"ajay"};

printf("\nroll:%d",class1.roll);
printf("name:%s",class1.name);	
}
*/
/******* 2nd Method *******/
//*
typedef struct stud
{
	int roll;
	char name[10];
}class1;
void main()
{
class1 new=(class1){1,"ajay"};

printf("\nroll:%d\t",new.roll);
printf("name:%s\n",new.name);	
}
//*/

