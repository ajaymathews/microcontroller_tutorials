#include<stdio.h>
union u_student
{
    int roll_no,roll_2;
    float m1,m2;
    char name[5];
}u_stud;
struct s_student
{
    int roll_no;
    float m1,m2;
    char name[10];
}s_stud;
void main()
{
printf("sizeof int:%d,sizeof float:%d,sizeof char:%d \n",sizeof(int),sizeof(float),sizeof(char));
printf("size of union =%d, size of structure =%d",sizeof(u_stud),sizeof(s_stud));
}
