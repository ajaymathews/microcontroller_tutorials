/* USED IN CASE OF NEED TO PASS THE ANY DATA BY
COMMND LINE, MAYBE AS AN OPTION FOR A CHOICE.*/

#include<stdio.h>
//int main(int argc, chaar **argv) //bth main has same meaning
int main(int argc, char *argv[])
{
	int i,conv_var;
	printf("argC:%d\n",argc);
	
	
	conv_var=atoi(argv[1]);//converts from string to integer
	
	printf("converted argumnt: %d\n",conv_var);
	for(i=0;i<=argc-1;i++)
	{
		printf("argv[%d]:%s\n",i,argv[i]);
	}
}

/********OUTPUT************/

/*if nothing is passed(bcz name is also passd), it shows 1 and name f pgm with path

argC:1
argv[0]:C:\Users\AJAY\Documents\PROGRAMS\C_PGMS\TUTORIAL\COMMND_LINE.exe


compiling the file first 
->gcc filename.c    //creates output file as a.exe
or 
->gcc filename.c -o any_name     //creates output file as any_name.exe
after Generating the .exe then only we are going to pass the argument as the command line
arguments
->filename a,b,c   //no need of calling via exe since,windws already support .exe  
                   //like calling chrome , unlike chrome.exe
                   //this a,b,c are the parameters , we are passing each as a string.
                  //so we can pass anything 

*/
