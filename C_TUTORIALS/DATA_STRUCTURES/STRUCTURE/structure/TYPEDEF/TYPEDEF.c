#include<stdio.h>
typedef struct 
{
	int rollno;
	char name[10];
}student;    //in this the student is the new data type instead of struct student

void main()
{
	student str_var;  //thus creating a memeber using the student type
	
	str_var.name="hello";
}
