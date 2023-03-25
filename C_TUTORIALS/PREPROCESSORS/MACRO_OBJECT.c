
/***********DEFINING VARIABLE**********/
/*

#include <stdio.h>       
#define PI 3.14   //defining a PI's value using the macro,

void main()
{
	printf("%f",pi);
}

*/
/***********DEFINING A FUNCTION**********/
/*

#include <stdio.h>       
#define cube(x) x*x*x    //defining a cube using the macro,in which x is the parameter

void main()
{
	cube(10);
}

*/
/***********DEFINING A NESTED FUNCTION**********/
/*

#include <stdio.h>       
#define cube(x) x*x*x
#define cucube(x) cube(x)*x //we could use the output of one defenition as the parameter of second

void main()
{
	cucube(10);
}

*/
/*********RUN A PGM WITHOUT USING MAIN()*********/
/*

#include <stdio.h>
#define start void main(){   //defining alterate for void main a start
#define msg printf("run without main successfully"); //to print a message
#define end }              //defining alternate for } as end

start
	msg
end

* /
/***********USING IFDEF & IFNDEF*******/
/*

#define test 20   //for testing purpose for ifndef and ifdef 
       
#ifdef test       //checking if the test is defined or not, if true execute till endif
	#define msg printf("the test is defined \n");	              
#endif

#ifndef test    //checking if the test is not defined
	#define msg printf("the test is not defined");
#endif

void main()
{
msg  
}

*/
/*************JOINING 2 TYPES*****************/


/*(not working*/
/*
#include<stdio.h>
#define JOIN(a,b) a##b

void main()
{
	char x[20];
	int i;
	for(i=0;i<=5;i++)
	   {
	    x=JOIN(user,i);
		printf("\n%s",x);
	   }
}
//but actually it does is joining the variable name to give a new variable name.
*/



#include <stdio.h> 
#define joinvar(a,b) a##b
int main(void) 
{ 
    int xy = 30,x=10,y=100; 

    printf("%d", joinvar(x, y));   //joins x & y and form xy, which is 30
    return 0; 
} 

