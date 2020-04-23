/*File Name     :finacase1.cc
  Author Name   :Syama
  Description   :To display the output in the given format*/

 /*CASE 1 :Parse the given command line and display in the below format
Input: parser.exe 1 a ppp 4.5643
Output:
Type Vaule Size of
Char A X
Int 1 X
String Ppp X
Float/double 4.5643 X
Note: X means are actual sizeof() value depends on the OS */
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main(int argc,char* argv[])
{
    if(argc>=2)
	{
    	if(strcmp(argv[1],"-h")==0) 	//For program usage through commandline argument -h
    	{
    cout<<"Usage:\nThis program is used to find the type of variable and its size"<<endl;
	}

	else
	{
   
    cout<<"Type\tValue\tSize of"<<endl;
    for(int iK=1;iK<argc;iK++)
    {
        int  aiVar=atoi(argv[iK]);     // function to convert string to Integer
        if(aiVar==0)
        {
            if(strlen(argv[iK])==1) //if condition to check for char or string
            cout<<"Char\t"<<argv[iK]<<"\t"<<strlen(argv[iK])<<endl;
            else
            cout<<"String\t"<<argv[iK]<<"\t"<<strlen(argv[iK])<<endl;
            
        }
        else
        {
            float afVar=atof(argv[iK]);      // function to convert string to Float
            if(aiVar==afVar)                   //if condition to check for Int or Float
            {
                cout<<"Int\t"<<aiVar<<"\t"<<sizeof(aiVar)<<endl;
                
            }
            else
            cout<<"Float\t"<<afVar<<"\t"<<sizeof(afVar)<<endl;
            
        }
    }
	}
	}
	
    return 0;
}
