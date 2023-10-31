#include<iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise(){
    queue<TreeNode<int>*> pendingNodes;
    int rootData;
    cout<<"Enter Root Node data"<<endl;
    cin>>rootData;
    TreeNode<int> *root= new TreeNode<int>(rootData);
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter Number of children for "<<front->data<<endl;
        int children;
        cin>>children;
        for(int i=0;i<children;i++){
            int childData;
            cout<<"Enter the data of child"<<endl;
            cin>>childData;
            TreeNode<int> * child= new TreeNode<int> (childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

void printTree(TreeNode<int>* root){
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
        cout<<root->children[i]->data<<",";
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

int main(){
    TreeNode<int>* root=takeInputLevelWise();
    printTree(root);
}
