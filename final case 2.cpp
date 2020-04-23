/*File Name     :finacase2.cc
  Author Name   :syama
  Description   :sum of square of positive numbers*/

#include<iostream>
#include<string.h>
using namespace std;
int squaresum(int iNum) 
{ 
    // condition for positive integer
    if(iNum>=1)
    {
    //Formula for the sum of squares 
	return (iNum * (iNum + 1) * (2 * iNum + 1)) / 6; 
    }
    else 
     cout<<"Only the positive values are allowed:  "<<endl;
} 
int main(int argc, char *argv[])
{
	//checking arguments to display -h
	if(argc>=2)             
	{
		if(strcmp(argv[1],"-h"))
		cout<<"Usage :"<<endl;
		cout<<"Input : Integer"<<endl;
		}
	else
	{
		// declaration of variable 
		int iNum;               
		cout<<"Enter Positive Integer"<<endl;
		cin>>iNum;
		//function call
        cout<<"Sum of Squares of N numbers = "<<squaresum(iNum)<<endl;
		
	}
}
