/*******Overloading operator***********/
/*using this we can 2 object variables and store the result in other
object with the variable.*/
/* we can add or do any operation on object just name it operator(+,-,*,/) as function name, let operator is + 
then whenevr we add 2 objects, the funcion 'operator+' is called, if we want to add 2 obj variables, then we must 
write that operations in defenition, eventhough it looks like we does obj1 + obj2, actually the form is obj1.+( obj2 )
+ will act like a '+()'  plus function*/

/*************FIRST_METHOD***************/
/*
#include<iostream>
using namespace std;
class rectangle
{	private:
		int length,breadth;
	public:
		void set_length(int);
		int get_length();
		void set_breadth(int);
		int get_breadth();
		rectangle operator+(rectangle);
		void operator/(rectangle);
		rectangle(int l=0, int b=0)
		{	set_length(l);
			set_breadth(b);}		
};

void rectangle::set_length(int l)
{	length=l;	}

void rectangle::set_breadth(int b)
{	breadth=b;}

int rectangle::get_length()
{	return length;	}

int rectangle::get_breadth()
{	return breadth;	}

//rectangle rectangle::add_rec(rectangle r)
rectangle rectangle::operator+(rectangle r)
{	rectangle temp;
	int l= get_length()+r.get_length();
	temp.set_length(l);

	int b= get_breadth()+r.get_breadth();
	temp.set_breadth(b);

	return temp;}

void rectangle::operator/(rectangle r)
{	cout<<"the / function is executed";	}

int main()
{	rectangle r1(10,20);
	rectangle r2(20,30);
	//rectangle r3 = r1.add_rec(r2);
	rectangle r3 = r1 + r2 ;
	cout<<"sum  l: "<<r3.get_length()<<" b: "<<r3.get_breadth()<<endl;
	r1 / r2 ;	}
*/

/***************USING_FRIEND_FUN***************/
/*
#include<iostream>
using namespace std;
class rectangle
{	private:
		int length,breadth;
	public:
		int getlength();
		int getbreadth();
		friend rectangle operator+(rectangle,rectangle); //this fun will add 2 parmeter(obj) passed	, notethe keyword 'friend'
		rectangle(int l=0, int b=0)
		{	length=l;
			breadth=b;	}	
};	
int rectangle::getlength()
{return length;}

int rectangle::getbreadth() //these function are insde clss, thus 'rectangle :: '
{return breadth;}

rectangle operator+(rectangle r1,rectangle r2) //but this is a friend function, thts y. 'rectngle::' is not used.
{
	rectangle temp;
	temp.length=r1.length + r2.length;
	temp.breadth=r1.breadth + r2.breadth;
	return temp;	
}
int main()
{	rectangle r1(10,20);
	rectangle r2(20,30);
	rectangle r3 = r1 + r2 ;
	cout<<"sum  l: "<<r3.getlength()<<" b: "<<r3.getbreadth()<<endl;
}
*/	
/*************** cout<< as operator overloading ************/
	
#include<iostream>
using namespace std;
class rectangle
{	private:
		int length,breadth;
	public:
		int getlength();
		int getbreadth();
		friend ostream &operator<<(ostream &o, rectangle r1);/* this will support friend method,in this we are trying to pass the cout also as an object
		and returning the cout object, for that we need to use the type ostream for cout with '&' operator.*/
		rectangle(int l=0, int b=0)
		{	length=l;
			breadth=b;	}	
};	
int rectangle::getlength()
{return length;}

int rectangle::getbreadth() //these function are insde clss, thus 'rectangle :: '
{return breadth;}

ostream &operator<<(ostream &o,rectangle r1) //note that all the ostream type contains a '&' sign with them .
{
o<<r1.getlength()<<r1.getbreadth();
return o;
}
int main()
{	rectangle r1(10,20);
	cout<<r1; //in usual cases we cant cout an object, so we use 'cout<<' as a function to display object details.
}	
	
	
	
	
	
	
	
