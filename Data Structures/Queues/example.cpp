
#include<iostream>
#include "QueueUsingArray.h"
using namespace std;
int main(){
    QueueUsingArray<int> q(10);
    q.isEmpty();
    cout<<q.dequeue()<<endl;
    q.enqueue(10);
    cout<<q.getFront()<<endl;
    q.enqueue(20);
    q.dequeue();
    q.enqueue(30);
    int x=q.getFront();
    cout<<x<<endl;
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.dequeue();
    cout<<q.getFront()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
    return 0;
}
