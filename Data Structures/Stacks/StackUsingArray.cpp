#include<climits>
#include<iostream>
using namespace std;

class StackUsingArray
{
private:
    int *data;
    int capacity;
    int nextIndex;
public:
    StackUsingArray(int totalSize){
        capacity=totalSize;
        data = new int[capacity];
        nextIndex=0;
    }
    void push(int element){
        if(nextIndex==capacity)
        cout<<"Stack is Full"<<endl;
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

    ~StackUsingArray(){
        delete[] data;
    }
};

