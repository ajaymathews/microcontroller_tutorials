#include<iostream>
using namespace std;
class student
{
	private:
		int roll;
		string name;
		float mark[3];
	public:
		int read_data(int,string,int*);
		int check_valid(int num);
		int total_mark();
		grade();
		
	
};
int student::read_data(int s_roll,string s_name,int s_mark[])
{
	this->roll=check_valid(s_roll);
	for(int i=0;i<3;i++)
	{this->mark[i]=check_valid(s_mark[i]);}
}
int student::check_valid(int num)
	{if(num<0)
		return 0;	
	}
int student::total_mark()
	{	int total=0,percent;
		for(int i=0;i<=3;i++)
		{	total+=this->mark[i];	}
		percent=total/3;
		cout<<"Name:"<<this->name<<endl<<"Percent :"<<percent<<"%";
	}
int main()
{
	int s_roll, s_mark[3];
	string s_name;
student s;
cout<<"Enter Roll_no :";
cin>>s_roll;

cout<<"Enter name :"; 
cin>>s_name; 
cout<<endl;

cout<<"Enter Marks of 3 "<<endl;
for(int i=0;i<3;i++)
{cout<<":";
cin>>s_mark[i];}

s.read_data(s_roll,s_name,s_mark);
s.total_mark();
}	
