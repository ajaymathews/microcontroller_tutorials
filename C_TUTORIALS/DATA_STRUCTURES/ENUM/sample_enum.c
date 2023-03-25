#include<stdio.h>
//enum colours{black,blue,green};//black=0,blue=1,green=2
//enum colours{black,blue=8,green};//black=0,blue=8,green=9
void main()
{
/*
	int z;
	z=blue;
	printf("Black:%d\nBlue:%d\nGreen:%d\n",black,blue,green);
*/

enum colours {red,blue,green};
enum colours yellow;
yellow=green;
printf("%d",yellow);


}
