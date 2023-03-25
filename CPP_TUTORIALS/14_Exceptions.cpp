/*try and catch works even from the functions, also we can throw a clsss object, and by that we can have any number of
thrws as the different types of classes used*/
#include<iostream>
using namespace std;
class ex
{	public:
		int x;
		char y;
		float z;
		void display(){
			cout<<"display function in class";	}	
};

/* int fun(int b)throw(char) , this is also a function defenition heading using throw */
int fun(int b)
{	if(b==0)
		{cout<<"(in function)b becomes zero,throwing charcter"<<endl;
		 throw 'x';	}
	cout<<"b returned"<<endl;
	return b;}



/*its better to use only one try..catch insde the main(), can have multiple catch, but 1 try */	
int main()
{
	int a=1,b=1;
	ex my_ex; //creating an object of ex class
	
	try 
	{	if(a==0)
		{	cout<<"(in main) a becomes zero, throwing integer"<<endl;	
			throw 1; //upon execution of throw, the control jumbs to the catch
		}
		
		else if(b==0){
			fun(b);	}	
		
		else{
			cout<<"throwing the object"<<endl;
			throw my_ex;	}	
	}
		
			
	catch(char c){
		cout<<"char value catched:"<<c<<endl;}
		
	catch(int x){
		cout<<"integer value catched:"<<x<<endl;}
		
	catch(ex catch_ex){    //this will catch the object, but if there is a parent class object and child class object
						  //then it is noted that the order of catch must be firstly the catch(child object) and then only the catch(parent class)
		cout<<"ex object is catched"<<endl;
		catch_ex.display();				}
	
	
	catch(...){ //this catch will catch all the data irrespective of the type
	cout<<"some data of some type is catched"<<endl;	}
	
}
