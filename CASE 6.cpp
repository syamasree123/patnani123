/*Purpose 	:Program to display the int and char variables for the given object. 
Language	:C++
Author  	: Manikanta Yelisetti
Date    	: 11/04/2020
*/
using namespace std;
#include<iostream>
#include<string.h>

class Sample
{
  int *iA;   //variable declaration
  int iN;
  char *cStr;
  public:
  	Sample(int iX)    //constructor
  	{
  		iN = iX;
  		iA = new int[iN];
	}
	Sample(char *iX)   //parameterised constructor
	{
		cStr = iX;
	}
   void display(void)    //display function
   {
   	cout<<"The String is : "<<cStr<<endl;
   }
   void display(int iX[])
   {
   		iA = iX;
		cout<<"The array elements are : ";
   		for(int iI=0;iI<iN;iI++)
   		{
   			cout<<"\t"<<iA[iI];
		}
		cout<<"\n";
   }
   ~Sample()    //destructor
   {
   		delete iA;
   		delete cStr;
   		cout<<"\nMemory Deleted for array and string";
   }
}; // end of class

int main(int argc,char* argv[])
{
    if(argc>=2)
	{
    	if(strcmp(argv[1],"-h")==0) 	//For program usage through commandline argument -h
    	{
    		cout<<"Usage:\nProgram to display the int and char variables for the given object"<<endl;
    	}
	}
	else
	{	
		Sample s1(5);   //object declaration
		Sample s2("welcome");
		int iA[] = {10,20,30,40,50};
		s1.display(iA);  //calling display functions
		s2.display();
	}
}
