#include<iostream>
#include<string.h>
using namespace std;

class Student{
    int rollNo;
    char *name;
    int fee;
    public:
    //Initialisation List :fee(fee)
    Student(int rollNo,char *name,int fee): fee(fee){
        this->rollNo=rollNo;
        //Shallow Copy
        // this->name=name;
        //Deep Copy
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
    }
    void print(){
        cout<<"roll number: "<<rollNo<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Fee: "<<fee<<endl;
    }
};