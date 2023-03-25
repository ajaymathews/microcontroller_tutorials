/*static variable and globl varible are stored in the code section below the stack memory.(that is lowest bottom)


/******* function overloading********/
						/*it is done by using the same function with different numbers of parameter or different 
						type parameter with same function name, return type of function is irrelevnt in this */
/*

#include<iostream>
using namespace std;

int fun(int x,int y)
{cout<<"int fun(int,int) "<<x<<" : "<<y<<endl;}

int fun(float x,int y)
{cout<<"int fun(float,int) "<<x<<" : "<<y<<endl;}
 
int fun(int x,int y,int z)
{cout<<"int fun(int,int,int) "<<x<<" : "<<y<<" : "<<z<<endl;}
 
int main()
{fun(10,20);
fun(10.5f,20); //to pass a float value to fun it need to be with 'f', bcz, normally it taken as double	
fun(10,20,30);} 
*/

/************ add function *********/
/*
void add(int x,int y)
{cout<<x+y<<endl;}
void add(float x,float y)
{cout<<x+y<<endl;}
void add(int x,float y)
{cout<<x+y<<endl;}
void add(float x,int y)
{cout<<x+y<<endl;}

int main()
{
	add(10,20);	
	add(10.6f,20);
	add(20.3f,50.9f)
} 
*/


/********** Function Template **************/
/*
#include<iostream>
using namespace std;
template <class T> // we cant use function overrloading with T, as same 							  function with parameter varied as T 
				/*  void add(T x,float y)
					{cout<<x+y<<endl;}
					void add(T x,int y)
					{cout<<x+y<<endl;}    */ //add is to do addition on all type of datatypes,even mixed datatypes but, Shows error

			   //this T will be changed to the data type as per the parameter passed,
/*
T fun(T x,T y)// thus we can use same function with 2 type of parameter
{cout<<"T fun(T,T) "<<x<<":"<<y<<endl;}
 
int main()
{fun(10,20);
 fun(10.5f,20.2f); 
 fun('a','k');
 //fun(1,'a'); //we cant use this because at a time t will recieve only one type.
}

/***** template in array passsing*******/
/*
#include<iostream>
using namespace std;
template <class T>
			   //this T will be changed to the data type as per the parameter passed,
T fun(T x[],T y[])// thus we can use same function with 2 type of parameter
{cout<<"T fun(T,T) "<<x<<":"<<y<<endl;}
 
int main()
{ int i_arr[]={9,6,4,5,8,3,4,9,6,6};
char s_arr[]="hello world";
 
 fun(s_arr,s_arr); 
 fun(i_arr,i_arr);
}
*/



/******* Default arguments******/
/*
#include<iostream>
using namespace std;
//when the number of parametrs differ,in 2 parmeter case,3rd is taken as zero default,
//and in 3 parametrs case, the z is assigned the passed value, z=0 is ignored,but make sure
int fun(int x,int y,int z=0;)        //that the default parmetr comes at right
{cout<<"int fun(int,int,int) "<<x<<":"<<y<<":"<<z<<endl;}					
int main()
{ 
 fun(1,2); 
 fun(1,2,3);
}

/*
void add(T x,T y,T z=0)
{cout<<x+y+z<<endl;}
int main()
{   add(10.6f,20.8f,0.9f);
    add(10.6f,20.8f);	} 
*/



/************ call by refernce ***************/
/*actually using call by value method, it can acess the variable loaction like call by adresss*/
/*
#include<iostream>
using namespace std;
int fun(int &a,int &b)//jut include a '&' next to the parameter
{a=a+10;
b=b+10;  }
 
int main()
{int x=1,y=2;
 fun(x,y);
 cout<<"int fun(int,int) "<<x<<":"<<y<<endl; 
}*/




/********Function pointer*************/
//same as C
/* 
int sum(int x,int y){
	return x+y;     }
int diff(int x,int y){
	return x-y;     }
int main()
{
	int (*fp)(int,int);
	fp=sum; cout<<"sum:"<<fp(10,9)<<endl;//or (*fp)(10,9);
	fp=diff; cout<<"diff:"<<fp(10,9)<<endl;
}  */

