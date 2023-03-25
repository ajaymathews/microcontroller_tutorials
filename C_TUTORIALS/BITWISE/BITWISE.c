#include<stdio.h>
void main()
{
	int a=10,b=11;
	printf("a&b:%d\n",a&b);//1010 & 
	                       //1011   =1010
	                 
	printf("a|b:%d\n",a|b);//1010 |
	                       //1011   =1011
	                 
	printf("a^b:%d\n",a^b);//1010 ^ (1^1 =0, 0^0=0, 1^0=1)
	                       //1011   =0001
	                 
	printf("a<<2:%d\n",b<<2);//1011<<2 =101100(44) shifting everything right and
	                                           // inseting 2 zeros to the right
	                                        //since the int is 4 byte it has the sspace of 32 bits
	                                        //thats why the ans 44, else olny 8 comes
    
	printf("a<<2:%d",b>>2);//1011>>2=0000010  shifting everything right and
	                                       // inserting 2 zeros to the left
}
