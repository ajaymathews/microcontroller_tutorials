/*
#include<iostream>
using namespace std;
class rectangle
{	public:
		int length,breadth; //by deafult it become private,so we cant access this from main() 
	     					//therefore to acess it in main(), use public:	
		int area()
		{ return (length*breadth); }
		
		int peri()
		{ return (2*(length+breadth)); }	};
		
/******** creating a class and its objects*********/
/*
int main()
{	rectangle r1,r2;//this r1 and r2 are the objects.
	r1.length=10;
	r1.breadth=20;
	cout<<r1.area();	}
*/

/******** acessing class using pointer*********/
/*
int main()
{ 
/*creating a norml class pointer and assigning object adress to it,
  here the varibles to the object(r1.length, etc..) are created in stack.*/ 
		/*
		rectangle *r_ptr, r1;//this r_ptr is the pointer to object, for that it must be type of class.
		r_ptr = &r1; //this is the important step,only this will point the object to the pointer
		*/
	
/*creating an object with its members on a heap memory using pointer	*/
/*
		rectangle *r_ptr = new rectangle(); 
		r_ptr->length=10;
		r_ptr->breadth=20;
		cout<<r_ptr->area();
} */




