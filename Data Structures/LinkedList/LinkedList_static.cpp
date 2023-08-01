#include<iostream>
using namespace std;
#include "Node.cpp"

void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    //Statically allocation
    Node n1(10); 
    Node *head = &n1;
    Node n2(20);
    n1.next = &n2;
    Node n3(30);
    n2.next = &n3;
    print(head);
}