#include<iostream>
using namespace std;
				        // std::cout, std::cin is the operation in normally
						//we can remove this std:: by using 'namespace std' on top*/
int main()
{
	int r_num=10, val=INT_MAX;  //val(22) : similar to val=22
	float f_val=100.548585L; //prints100.549 which is that it prints only 6 digits,and the last digit will be 1 added or 1 reduced
							//based on the last value < 5 or >= 5, if it was 1000000.563837 then prints 100001 
	/*
	string name;//instead of char name[20], string is better because getline() operates only on string type.
	cout<<"Enter RollNum and Name:";
	//cin>>r_num>>name;//reads string and number, but doesnt read spaces.
    // //this function reads string with spaces also
	
	getline(cin,name); 
	
 	cout<<"Name:";
	cout<<"RollNo:"<<r_num<<endl<<"Name:"<<name<<endl;
	*/
	
	cout<<"Maximum Integer:"<<val<<endl;
	cout<<"Maximum Float:"<<f_val<<endl;
	cout<<"Name:"<<name<<endl;

	return 0;
}
