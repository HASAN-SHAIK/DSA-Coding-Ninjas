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

void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int> * front = pendingNodes.front();
        cout<<front->data<<":";
        pendingNodes.pop();
        int size=front->children.size();
        for(int i=0;i<size;i++){
            pendingNodes.push(front->children[i]);
            if(i==size-1)
            cout<<front->children[i]->data;
            else
            cout<<front->children[i]->data<<",";
        }
        cout<<endl;
    }
}

int main(){
    TreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
}
