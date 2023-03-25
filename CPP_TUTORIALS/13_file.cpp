#include<iostream>
#include<fstream>
using namespace std;

int main(){
/*******FILE WRITE*********/
/*OPENING FILE*/
/*
ofstream outfile("text1.txt");//this will create a file and starts to write in new, outfile(we can use any name)
//ofstream outfile("text1.txt",ios::app);// is the object to write to a file, if we are using ,ios::app' then opens in append mode
 	

// ANOTHER METHOD //
ofstream outfile;
outfile.open("text3.txt");


// WRITING TO FILE //
// writing into this outfile is same as writing into the file
outfile<<"woooooorld"<<endl;
outfile<<55;

outfile.close(); //file closing
*/





/*********READ FILE***********/
/*OPEN IN READ MODE*/

string indata;

ifstream infil("text1.txt"); //this opening wont create a file, only opens the existing one
if(!infil)
cout<<"file cannot be opened";

infil>>indata; //this will collesct the data into the indata varaible, but reads only a line, to read another line
cout<<indata;   //we neeed to repeat these lines

if(infil.eof())
{
	cout<<"end of file is reached";
}

infil.close();

}

