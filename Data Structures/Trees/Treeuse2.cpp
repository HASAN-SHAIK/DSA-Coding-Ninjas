#include<iostream>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout<<"enter the Number of Children for "<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the data of child "<<i+1<<endl;
        TreeNode<int>*child= takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>* root){
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
        cout<<root->children[i]->data<<",";
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

int main(){
    TreeNode<int>* root=takeInput();
    printTree(root);

}