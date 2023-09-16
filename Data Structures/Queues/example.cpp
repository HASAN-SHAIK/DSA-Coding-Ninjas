#include<iostream>
#include "QueueUsingArray.h"
using namespace std;
int main(){
    QueueUsingArray<int> q(10);
    q.isEmpty();
    q.dequeue();
    q.enqueue(10);
    q.front();
    q.enqueue(20);
    q.enqueue(30);
    q.front();
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.dequeue();
    q.front();
    q.getSize();
    q.isEmpty();

}