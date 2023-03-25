
#include "H_file.c"  //" " is used to include a .c file or .h file into the main program
void main()
{
	printf("value from file:%d\n",x);
	
	printf("value from #def:%f\n",pi);
	
	printf("output from #define function :%d\n",cube(2));//calling function defined using macro in another program
	
	fun(20); //calling function defenition in another program
}-
