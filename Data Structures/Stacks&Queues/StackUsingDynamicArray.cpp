#include<climits>
#include<iostream>
using namespace std;

class StackUsingDynamicArray
{
private:
    int *data;
    int capacity=4;
    int nextIndex;
public:
    StackUsingDynamicArray(){
        data = new int[capacity];
        nextIndex=0;
    }
    void push(int element){
        if(nextIndex==capacity){
            int *newdata=new int[capacity];
            for(int i=0;i<capacity;i++)
            newdata[i]=data[i];
            capacity*=2;
            delete [] data;
            data=newdata;
        }
        else{
            data[nextIndex++]=element;
        }
    }
    void pop(){
        if(nextIndex==0)
        cout<<"Stack is empty"<<endl;
        else{
            nextIndex--;
            cout<<"Deleted "<<data[nextIndex]<<endl;
        }
    }
    int top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
    int size(){
        return nextIndex;
    }
    int isEmpty(){
        return nextIndex==0;
    }

};
