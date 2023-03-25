/*TOGGLE NTH BIT OF A NUMBER*/

#include<stdio.h>
void main(){
	int num,n;
	printf("enter the num:");
	scanf("%d",&num);
	printf("enter the bit:");
	scanf("%d",&n);
//	printf("%d",num^(1<<n));//TOGGLE
	printf("%d",num|(1<<n));//SET
//    printf("%d",num&~(1<<n));//RESET
}

	


