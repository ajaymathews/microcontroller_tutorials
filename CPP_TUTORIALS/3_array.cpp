#include<iostream>
using namespace std;
int main()
{
/*********Character array************/
/*
char c_arr[]={'h','e','l','l','o'};//or a_arr[]="hello world" ;
string s_arr="hello world";//the string is same as char array in these operations
cout<<c_arr<<endl;

cout<<"first charctr: "<<c_arr[0]<<endl;//this will print first charcter as in c;
cout<<"c_arr: "<<c_arr<<endl;//but instead of first charcter ,this will print whole arry
cout<<"s_arr: "<<s_arr<<endl;



/***********Integer array**************/

int i_arr[]={1,5,3,8,2};
/* 
cout<<"i_array: "; 
for (int i=0;i<=4;i++)
{
cout<<i_arr[i]; 
}
cout<<endl;
*/

/*****pointer arithmetic*****/

cout<<"i_array: "; 
for (int i=0;i<=4;i++)
{
cout<<*(i_arr+i); //array usng pointer arithmetic
//i_arr++;       //dosnt go to the next array elemnt if it is initialised as array, will work if it is initialised using pointer as dynamic array
}
cout<<endl;

}

/*****Dynamic memory allocation for array********/
/*
int i=10;
//int *dy_arr = new int[10]; //this will allocate a 10 integer spaces in the heap memory under the name dy_arr,
int *dy_arr = new int[i]; //this also will work fine
for(i=0;i<10;i++){
	cout<<"dy_arr["<<i<<"]: ";
	cin>>dy_arr[i];
}

cout<<"dy_arr[]=";
for(i=0;i<10;i++){
cout<<dy_arr[i]<<" ";
}
cout<<endl;

delete[]dy_arr; //freeying the dynamic memmory alocated
dy_arr=NULL; // initilaizing it to a null value to avoid a wild pointer scenerio


}
*/
