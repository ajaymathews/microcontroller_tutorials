/*templete is is used when we need to have different data type class object with the
same class, thus the T becomes different typ as by the object creation*/

#include<iostream>
using namespace std;
template<class T>
class stack
{
	private:
		T data[];
		int pos;
	public:
		void push(T x);
		T pop();
};
template<class T>
void stack<T>:: push(T x) //in this method no need of putting the public type or private for child class
{
	cout<<"Pushing data";
}
template<class T>
T stack<T>:: pop()
{
	cout<<"poping data";
}
int main()
{
	stack<int> s1;
	stack<char> s2;
	s1.push(10);
	s2.push(11.2);//it should be char type, but idk its works.
	
	s1.pop();
}
