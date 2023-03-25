/* using the keyword friend inside the base class with a function or another class, we can make any function or class
a friend of the base class,so by that we can acess the members of base class to the friend function or class and
then,  outside the class it can be defined or operated as any normal function or class, */
/*
#include<iostream>
using namespace std;
class derr; //this is to notify the compiler that there is a class named derr,othervise when executing friend derr, shws error
class base
{
	private:
		int a=10,b=20;
	public:
		set_var(int,int);
		int get_a();
		int get_b();
		//friend void sum();
		friend derr; //here the derrived class is friend of base and thus derrived can acess the varibles,
					// by creating an object of base class in derr class 
};
class derr
{
	private:
		int c;
	public:
		base obj;
		void sum(){
			c=obj.a+obj.b;
			cout<<"sum:"<<c<<endl;
		}
		
};
/* //this function s for when friend sum() is used
void sum()
{
	base obj; //defining an object of class base on function, and using function as friend acessing the variables.
	int c=obj.a+obj.b;
	cout<<"sum="<<c;
}
*/
/*
int main()
{
	derr d;
	d.sum();
}
*/
/******Static members and functions*/
/*
#include<iostream>
using namespace std;

class base
{
	private:
		int a=10,b=20;
	public:
		static int count;
		void demo()
		{
			cout<<"inside demmo";
		}
		void sample()
		{
			count++;
			cout<<"count:"<<count;
		}
		static fun()
		{
			count --; //only static bariable can be used inside the static function.
			//eg:creatiing a constructor to crwate students, as the student objet is creted admmsn no ++ in constructor
		}
};
int base::count=0; //to use a static variable, it also should be writtten outside the class or main, like global.  
int main()
{
	base b1,b2,b3;
	//b1.sample();
	//b2.sample();
	b3.sample();//the varaible count is shared amoung all the object,thus value one objects use is same as the other objects. 
}
*/
/* a class inside another class can be created*/ 
#include<iostream>
using namespace std;

class linkedlist
{
	private:
		int max_length;
	public:
		static int count;
		class node
		{
			int data;
			int *addr;
		}
		node *n1;//here the class linkedlist can create objects of node and use it as own.
};
void main()
{
	linkedlist::node n2;
}



