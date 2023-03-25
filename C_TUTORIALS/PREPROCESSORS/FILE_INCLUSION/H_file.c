#include <stdio.h>
#define pi 3.14 //to check if #define is passed to next pgm.
#define cube(x) x*x*x  //to check the function paramtr is pased to here
//int a=10;
extern int x=5000;   //witout the extern the main program couldnt reconize the x.
void fun(int a)  //this is the defenision of the function,calling is in othr pages.
{
	printf("Inside function for paessed 20%d",a);
}
 //extern keyword is used to share the variable with the file which opening this file.
                   //void main shouldnt be used in this. only in main pgm

