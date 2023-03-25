#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int i,k;
    struct student
    {
        char name[10];
        int rollno;
        float mark[7];
    }s[10];
    for(i=0;i<2;i++)
        {
        printf("\n Enter the name of student:");
        gets(s[i].name);
        fflush(stdin);
        printf("\n Enter the Roll-No of student:");
        scanf("%d",&s[i].rollno);
        fflush(stdin);
        printf("\n enter the mark of  student:");
        for(k=1;k<5;k++)
        {
      printf("\n%d subject:",k);
      scanf("%f",&s[i].mark[k]);
        }
         fflush(stdin);
}
    printf("The complete dataof students \n");
    printf("------------------------------- \n");
    for(i=0;i<2;i++)
        {
        printf("\n");
        puts(s[i].name);
        printf("\n The Roll-No of student:%d",s[i].rollno);
        printf("\n The mark of  student:");
        for(k=1;k<5;k++)
        {
        printf("\n %d subject:%f",k,s[i].mark[k]);
        }
        }
}
struct student
    {
        char name[10];
        int rollno;
        float mark[7];
    }s[10];
