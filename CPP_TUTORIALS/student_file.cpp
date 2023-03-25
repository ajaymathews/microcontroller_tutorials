#include<iostream>
#include<fstream>
using namespace std;
int i=1;
class student
{
	public:
		int roll_no;
		char name[20];
		float mark;
		char division;
		friend ofstream &operator<<(ofstream &f_w, student &s); 
};
ofstream &operator<<(ofstream &f_w, student &s)
{
	//cout<<"insideoverload";
	f_w<<i<<"."<<endl;
	f_w<<s.name<<endl;
	f_w<<s.roll_no<<endl;
	f_w<<s.mark<<endl;
	f_w<<s.division<<endl;
	i++;
	cout<<"outofoverload";
}
int main()
{
	int n,i;
	string name;
	ofstream f_w("student_details.txt");
	// student details //
	cout<<"enter the number of students :";
	cin>>n;
	cout<<endl;
	student s;	
	f_w << s;
/*		
	for(i=0;i<n;i++)	{
		student s[i];
		cout<<i<<".";
		cout<<"Enter the Roll No:";
		cin>>s[i].roll_no;
		cout<<"  Enter the Name:";
		cin>>s[i].name;
		cout<<"  Enter the Mark:";
		cin>>s[i].mark;
		cout<<"  Enter the Division:";
		cin>>s[i].division;  
		
		
		f_w << s[i];	//here we are going to overload the operator		
		} 
*/
}
