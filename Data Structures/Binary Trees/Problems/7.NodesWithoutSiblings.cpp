#include<iostream>
#include "../BinaryTreeNode.h"
#include<queue>
#include<stack>
using namespace std;
void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
    return;
    if(root->right==NULL&&root->left!=NULL)
    cout<<root->left->data<<" ";
    if(root->left==NULL&&root->right!=NULL)
    cout<<root->right->data<<" ";
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}