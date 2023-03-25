#include<stdio.h>
void main(){
	int i=0,j=0;
//	char *str="hello";
//	char str1[]="howareyou";
//	char *str2[3]={"good","morning","ajay"};
//	char **str3={"what","evening","dae"};
//	int **arr={{1,2,3},{40,50,60},{700,800,900}};
//	printf("%s\n",str);
//	printf("%s\n",str1);
//	printf("%s %s %s\n",*(str2),*(str2+1),*(str2+2));


	char **doublepointer;
//	char **str3={"good","morning","ajay"};
	char *arraypointer[5]={"good","morning","ajay","hello","shyamannan"};
	
	doublepointer=&arraypointer[0];
	
	
	
	
	for(j=0;j<10;j++){
		printf("*( doublepointer +%d)-> %s\n",j,*(doublepointer+j));
	}
	//printf("%c\n",*(*str3)+1);
}
