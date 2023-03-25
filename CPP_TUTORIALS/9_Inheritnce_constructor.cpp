#include<iostream>
using namespace std;
class date
{
	private:
		int day,mon,yr;
	public:
		date(int d, int m, int y){	//constructor
			day=d;mon=m;yr=y;
			cout<<"executed base constructor"<<endl;}
			
		 ~date(){//this virtual destructor will destroy both derrived and base class
			cout<<"base class destructor is called"<<endl;}
};

class time : public date
{
	private:
		int hr,min,sec;
	public:
		time(int h, int m, int s):date(23,4,20){ //constructor of derrived class calling base classs, but note that when 2 constructors
		hr=h;min=m;sec=s;						//have written for the class, the priority goes on to non-parametirized
		cout<<"executed derrived class constructor"<<endl;}
		
		~time() {
			cout<<"derrived class destructor is called"<<endl;}
		
};
int main()
{
	time(5,56,12);
}

