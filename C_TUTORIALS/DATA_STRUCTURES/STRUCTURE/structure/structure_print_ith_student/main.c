//#include<stdio.h>
//#include<conio.h>
//#include<string.h>
//struct time
//{
//    int sec;
//    int min;
//    int hr;
//};




//struct time func(struct time t1)         // using method of passing structure and returning it
//{
//    printf("inside the function\n");
//    printf("hour=%d\n",t1.hr);
//    t1.hr=1;
//    t1.min=2;
//    t1.sec=3;
//    return(t1);

//    printf("hour=%d\t",t1.hr);
//    printf("minute=%d\t",t1.min);
//    printf("second=%d\n",t1.sec);

//}
//int main()                   main function call of structure fucnction
//{
//    struct time t1={0,0,0};
//struct time x1=func(t1);
//printf("inside the main\n");
//printf("hour=%d\t",x1.hr);
//printf("minute=%d\t",x1.min);
//printf("second=%d\n",x1.sec);
//}


// func( struct time* t1)         // using method of passing structure pointer
//{                      // using a constant on before the struct makes it read only : func(const struct time* t1)
//    printf("inside the function\n");
//    printf("hour=%d\t min=%d\t sec=%d\n",t1->hr,t1->min,t1->sec);
//    t1->hr=1;
//    t1->min=2;
//    t1->sec=3;
//}
//int main()
//{
//    struct time t1={0,0,0};
//func(&t1);
//printf("inside the main\n");
//printf("hour=%d\t",t1.hr);
//printf("minute=%d\t",t1.min);
//printf("second=%d\n",t1.sec);
//}



//    int i,k,found,n,j,ro;
//    typedef struct
//    {
//        char sub_name;
//        float max;
//        float mark;
//    }subject;

//    struct student
//    {
//        char name[10];
//        int rollno;
//        subject sub;
//    }s[3];
//    printf("enter the number of students present:");
//    scanf("%d",&n);
//    for(i=0;i<n;i++)
//        {
//        printf("\n Enter the name of student%d:",i);
//        fflush(stdin);
//        gets(s[i].name);
//        fflush(stdin);
//        printf("\n Enter the Roll-No of student:");
//        scanf("%d",&s[i].rollno);
//        fflush(stdin);
//        printf("\n enter the mark of  student:");
//        for(k=1;k<5;k++)
//        {
//      printf("\n name of subject:");
//      fflush(stdin);
//      gets(s[i].sub.sub_name);
//        }
//      fflush(stdin);
//printf("finding greatest roll no and printing it");
    //struct student x;
//     for(i=0;i<n;i++)
//     {
//         if((s[i].rollno<s[i+1].rollno)&&((i+1)<n))
//         {//printf("%d\n",s[i+1].rollno);
//             x=s[i+1];
//        printf("%d\n",s[i+1].rollno); }
//     }
//             printf("\n the name is:");
//             puts(x.name);
//             printf("\n The Roll-No of student:%d",x.rollno);
//             printf("\n The mark of  student:");
//             for(k=1;k<5;k++)
//             {
//             printf("\n %d subject:%f",k,x.mark[k]);
//             }

//    printf("enter the rollNo of studentto find:");
//    scanf("%d",&ro);
//    for(j=0;j<n;j++)
//    {
//        if(ro==s[j].rollno)
//        {
//            found=j;
//        }
//    }
//    printf("The details of student \n");

//        printf("\n the name is:");
//        puts(s[found].name);
//        printf("\n The Roll-No of student:%d",s[found].rollno);
//        printf("\n The mark of  student:");
//        for(k=1;k<5;k++)
//        {
//        printf("\n %d subject:%f",k,s[found].mark[k]);
//        }




