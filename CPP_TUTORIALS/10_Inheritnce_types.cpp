/*protected is another acess specifier like public, such as the derrived class can acess theprotected data from parnt, 
but when creating the object, the data cnnnot be acessed by the object,protected data can be acessde inside class,and derrived class.*/

#include<iostream>
using namespace std;
class parent
{
	private:
		int p_age,p_yr;
	public:
		void set_p_age(int);
		void set_p_yr(int);
		int get_p_age();
		int get_p_yr();
};
class son:virtual public parent //when the 2 classes are combined to give another, the combining calsses should need a keyword 'virtual'
{                               //here son and daughter combine to give the child class
	private:
		int s_age,s_yr;
	public:
		void set_s_age(int);
		void set_s_yr(int);
		int get_s_age();
		int get_s_yr();	
};
class daughter:virtual public parent
{
	private:
		int d_age,d_yr;
	public:
		void set_d_age(int);
		void set_d_yr(int);
		int get_d_age();
		int get_d_yr();	
};
class child: public daughter, public son
{
	private:
		int c_age,c_yr;
	public:
		void set_c_age(int);
		void set_c_yr(int);
		int get_c_age();
		int get_c_yr();	
};

void parent::set_p_age(int p_a){
p_age = p_a;}

void parent::set_p_yr(int p_y){
p_yr=p_y;}

int parent::get_p_age(){
return p_age;}

int parent::get_p_yr(){
return p_yr;}


void son::set_s_age(int s_a){
s_age = s_a;}

void son::set_s_yr(int s_y){
s_yr=s_y;}

int son::get_s_age(){
return s_age;}

int son::get_s_yr(){
return s_yr;}


void daughter::set_d_age(int d_a){
d_age = d_a;}

void daughter::set_d_yr(int d_y){
d_yr=d_y;}

int daughter::get_d_age(){
return d_age;}

int daughter::get_d_yr(){
return d_yr;}


void child::set_c_age(int c_a){
c_age = c_a;}

void child::set_c_yr(int c_y){
c_yr=c_y;}

int child::get_c_age(){
return c_age;}

int child::get_c_yr(){
return c_yr;}

		
int main()
{

parent p;	son s;	daughter d;  child c;
parent *p_ptr=&p;  son *s_ptr=&s;    daughter *d_ptr=&d;    child *c_ptr=&c;


c.set_p_age(101); //in this the value passed/ recieved by each object is differnt,
p.set_p_age(102); //value passd by c object cant be retrived by p object, 
                  //bcz both save in differnt locations in memeory
c.set_s_age(51);
c.set_d_age(41);
c.set_c_age(11);
cout<<"using object"<<endl;
cout<<"parent(c objct):"<<c.get_p_age()<<endl;
cout<<"parent(p objct):"<<p.get_p_age()<<endl;

cout<<"Son:"<<c.get_s_age()<<endl;
cout<<"Daughter:"<<c.get_d_age()<<endl;
cout<<"child:"<<c.get_c_age()<<endl<<endl<<endl<<endl;



p_ptr->set_p_age(110);
c_ptr->set_p_age(105);
cout<<"parent(c)"<<c_ptr->get_p_age()<<endl;
cout<<"parent(p)"<<p_ptr->get_p_age()<<endl;


p_ptr=&c;//this commnd is necessary to make the class p and c, to b accessed the same data from the class
p_ptr->set_p_age(110);
c_ptr->set_p_age(105);
cout<<"parent(c)"<<c_ptr->get_p_age()<<endl;
cout<<"parent(p)"<<p_ptr->get_p_age()<<endl;

c_ptr->set_s_age(50);
c_ptr->set_d_age(40);
c_ptr->set_c_age(10);
cout<<"using pointer"<<endl;
cout<<"Son:"<<c_ptr->get_s_age()<<endl;
cout<<"Daughter:"<<c_ptr->get_d_age()<<endl;
cout<<"child:"<<c_ptr->get_c_age()<<endl;

}
