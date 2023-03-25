/*POLYMORPHISM : function overiding is that, the function name that defined in parent clss and derrived class are similar,
then the object created by class will call the function in that classs.*/
/*
#include<iostream>
using namespace std;
class parent{
	public:
		void display(){
		cout<<"Display in parent"<<endl;}
};
class child: public parent{
	public:
		void display(){
			cout<<"Display in child"<<endl;}
};
int main()
{
	parent p;
	child c;
	p.display();
	c.display();
}
*/
/*
#include<iostream>
using namespace std;
class parent{
	public:
		int a,b;
		//virtual	void display(){
		void display(){ 
		cout<<"Display in parent"<<endl;}
};
class child: public parent{
	public:
		int c,d;
		void display(){
			cout<<"Display in child"<<endl;}
};
int main()
{
	parent *p=new child();//child() is not a constructor its also a classs.
	p->display();//in this normally the parent class will be called,
	             //but if we put a virtual near the parent class function, then by the function overloading
	             //instead of parent class it will look for same in derrived class and will execute it.

}
*/

#include<iostream>
using namespace std;
class base{
	int b1,b2;
	public:
	virtual	void sample1()=0;//this is the pure form of virtual unction, if this is usedd we can create object
	virtual void sample2()=0;//of the base class, we could create only pointer to the base class.
							//in which we can assign any derrived class.
};
class derrived : public base{
	int d1,d2;
	public:
		void sample1(){
		cout<<"function sample1";}
		void sample2(){
		cout<<"function sample2";}
};
int main()
{
	//base b;
	base *b_ptr;
	b_ptr=new derrived();
	b_ptr->sample1();
}


