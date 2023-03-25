#include<iostream>
using namespace std;
#define to_str(x) #x  //this preprocessor will convert x into charcter,
//thus if i write to_str(hello)  -> is equal to "hello"



/**********usage of constant in variable*********/
/*
int main(){
int x=10;
int y=20;
/*
const int *ptr=&x;
ptr=&y;//it can point to other variable, but cant modify.
++(*ptr);
(*ptr)++; these 2 oprations cant be performed, bcz sinceit is a const, we could only read from it,  not change any value
*/

/*
int *const ptr=&x;//in this metho, the pointer cant point to another,
//ptr=&y;
++(*ptr); //but can modify the value
*/
/*
const int *const ptr=&x;//then this cant be modified or point to another


cout<<*ptr;	
}
*/
/********usage of const in class************/
/*
class demo
{
	public:
		int a,b;
		void display();
};
void demo::display() const
{
	a++; //this operation wont be performed since const is used.
	cout<<a;
}

*/


/***********usage of namespace************/
namespace set1
{
	void display() //since the display is of same name we can use both function
	{
		cout<<"display inside the set 1"<<endl;
	}
}

namespace set2
{
	void display()
	{
		cout<<"display inside the set 2"<<endl;
	}
}

using namespace set1; //since this is used the set1 is taken normally
int main()
{
	display();
	set2::display();
}















