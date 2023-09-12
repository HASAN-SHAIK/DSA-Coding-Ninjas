#include<iostream>
using namespace std;
#include "Node.cpp"

//create a linked List until -1 is entered
Node* createLL(Node *head){
    cout<<"Enter data";
    int x;
    cin>>x;
    if(x==-1)
    return head;
    if(head==NULL&&x!=-1)
        head = new Node(x);
    Node *temp=head;
    cout<<"Enter data";
    cin>>x;
    while(x!=-1){
        temp->next = new Node(x);
        temp=temp->next;
        cout<<"Enter data";
        cin>>x;
    }
    return head;
}

//print
void printLL(Node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
} 

//Reverse

//Palindrome check

//Find a node

//Append Last N to First

//Eliminate duplicates in an ascending sequence

//Delete a node 

//Insert a node

//Print ith node

//Length of LL


int main(){
    Node *head = NULL;
    head = createLL(head);
    printLL(head);
    return 0;
}