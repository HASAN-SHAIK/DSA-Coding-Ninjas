
#include<iostream>
#include "QueueUsingArray.h"
using namespace std;
template <typename T>
int main(){
    QueueUsingArray<int> q(10);
    q.isEmpty();
    q.dequeue();
    q.enqueue(10);
    cout<<q.front()<<endl;
    q.enqueue(20);
    q.enqueue(30);
    int x=q.front()<<endl;
    cout<<x<<endl;
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.dequeue();
    cout<<q.front()<<endl;
    q.getSize();
    q.isEmpty();
    return 0;
}
