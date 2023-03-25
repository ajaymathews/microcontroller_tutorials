#include<iostream>
using namespace std;

template<class T>
class node{
private:
	int pos=0,size=10;
	T memory[] =new T[size];	
public:
	void push(T data);
	T pop();	
};

template<class T>
void node<T>::push(T d){
memory[pos]=d;
pos++;	}

template<class T>
T node<T>::pop()
{pop--;
return memory[pop+1];	}

int main()
{
	node<int> n1;
	n1.push(10);
	cout<<n1.pop();
}
