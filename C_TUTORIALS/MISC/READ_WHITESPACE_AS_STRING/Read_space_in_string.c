#include<stdio.h>
#include<string.h>
char printstring(char* ptrstr)
{
     puts(ptrstr);
}

int main()
{
    int n;
    printf("enter the limit of string");
    scanf("%d",&n);
    char *ptrstr=(char*)malloc(n*sizeof(char));
    if(ptrstr!=NULL)
    {
    printf("enter the string");
    scanf(" ");
    //scanf("%s",ptrstr);
    gets(ptrstr);
    printstring(ptrstr);
    }

    free(ptrstr);
}
