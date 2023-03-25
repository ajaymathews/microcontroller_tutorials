#include<stdio.h>
#include<stddef.h>
void main()
{
	int ch,num;
	printf("Enter the Following to be Checked ");
	while(1)
	{
	printf("1.NUMB\n");
	printf("2.ALPH\n");
	printf("3.SPCL\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			scanf("%d",&num);
			printf("isblank:%d\n",isblank(num));
			printf("islower:%d\n",islower(num));
			printf("isupper:%d\n",isupper(num));
			printf("isalpha:%d\n",isalpha(num));
			printf("isalnum:%d\n",isalnum(num));
			printf("isdigit:%d\n",isdigit(num));
			printf("ispunct:%d\n",ispunct(num));
	}
	
	}
	
}
