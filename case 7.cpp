/*File Name     :case7.cc
  Author Name   :Syama
  date          :23-04-20
  Description   :add and delete the files*/

#include<iostream>
#include<vector> 
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

class student{
    char c_Key;
    string s_Value;
public:
void getkey()
    {
        cout<<"Enter key:";
        cin>>c_Key;
    }

    void getvalue()
    {
        cout<<"Enter value:";
        getchar();
        getline(cin,s_Value);
    }

    char outkey()
    {
        return c_Key;
    }

    string outvalue()
    {
        return s_Value;
    }
    void display()
    {
        cout<<c_Key<<"\t"<<s_Value<<endl;
    }
};


int searchupdate(vector<student> &std,char cOption)
{
    student s;
    vector<student>:: iterator it;  //iterator creation to go word to word in file
    ofstream outfile("notes.ini",ios::trunc|ios::out|ios::binary);  //inorder to write updated value opened in write mode
    for(it=std.begin();it!=std.end();it++)  //iterating to contents stored in vector
    {
        s=*it;
        if(s.outkey()==cOption)
        {
            std.erase(it);  //the value is been deleted
            cout<<"Enter value to update"<<endl;
            s.getvalue();
            std.push_back(s);
            for(it=std.begin();it!=std.end();it++)
                outfile.write((char*)&(*it),sizeof(s));     //the file again written with updated values
            outfile.close();
            return 1;
        }
    }
}
void addtofile(vector<student> &std)
{
    student s;
    vector<student>:: iterator it;
    char cOption='y';
    while(cOption=='y')
    {
        ofstream outfile("notes.ini",ios::trunc|ios::out|ios::binary);
        s.getkey();
        if(searchupdate(std,s.outkey())==1) //checking for if the key is already present in the file or not
            cout<<"updated"<<endl;
        else
        {
            s.getvalue();
            std.push_back(s);   //all new entries has been pushed backed
            for(it=std.begin();it!=std.end();it++)
            outfile.write((char*)&(*it),sizeof(s));
        }
        cout<<"Do you want to append student data(y/n)?";
        cin>>cOption;
        outfile.close();
    }
}
void deletefromfile(vector<student> &std)
{
    char ckey;
    student s;
    vector<student>:: iterator it;
    ofstream outfile("notes.ini",ios::trunc|ios::out|ios::binary);
    cout<<"Enter the key to delete:";
    cin>>ckey;
    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        if(s.outkey()==ckey)
            std.erase(it);
    }
    if(outfile.eof())   
    {
        cout<<"The file Empty and is being removed"<<endl;
        remove("notes.ini");
    }
    for(it=std.begin();it!=std.end();it++)
        outfile.write((char*)&(*it),sizeof(s));
    outfile.close();
}


void showfromfile()
{
    student s;
    ifstream in("notes.ini",ios::in|ios::binary);
    while(1)
    {
        in.read((char*)&s,sizeof(s));   
        if(in.eof())break; 
            s.display();
    }
    in.close();
}

int main(int argc,char* argv[])
{
    if(argc>=2)
    {
        if(strcmp(argv[1],"-h")==0)     
        {
            cout<<"used to do certain file operations like add,update,delete and display using vector. Just select the option"<<" ";
            cout<<"Enter key a char and value as a string"<<endl;
        }
    }
    else
    {
        vector<student> std;
        vector<student>:: iterator it;
        student s;
        char cOpt;
        while(1)
        {
            cout<<"Select your option 1.add 2.delete 3.display"<<endl;
            cin>>cOpt;
            switch(cOpt)
            {
                case '1':
                        addtofile(std);
                        break;
                case '2':
                        deletefromfile(std);
                        break;
                case '3':
                        showfromfile();
                        break;
                default:
                        return 0;
            }
        }
    }
    return 0;
}

