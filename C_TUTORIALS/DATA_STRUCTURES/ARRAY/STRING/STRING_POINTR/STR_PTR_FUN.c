#include<stdio.h>
void main()
{
/*   //this will work, we can assign one string to other using pointer variable
	char *a="ajay",*b="boss",*temp;
	temp=a;
	a=b;
	b=temp;
	printf("a:%s \nb:%s \ntemp:%s",a,b,temp); //string can be assigned if string pointer is used
*/
	char *a,*b,*temp;
	a=malloc(10);
	scanf("%s",a);//for scanf,we need to allocate memory, oherwise it wont work.

printf("a:%s",a);	
}
