#include<iostream>
#include "Trie.h"
using namespace std;

int main(){
    // Trie *head;
    // head->insertWord("hasan");
    // head->insertWord("likith");
    // head->insertWord("abhinav");
    // bool x=head->searchWord("hasan");
    // if(x==true)
    //     cout<<"San=mple"<<endl;

    Trie head;
    head.insertWord("hasan");
    head.insertWord("likith");
    head.insertWord("abhinav");
    bool x=head.searchWord("hasan");
    if(x==true)
        cout<<"Sample"<<endl;
}
