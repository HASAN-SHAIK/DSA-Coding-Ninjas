#include<iostream>
#include "../BinaryTreeNode.h"
#include<queue>
#include<stack>
using namespace std;

int getSum(BinaryTreeNode<int>* root) {
    // Write your code here
	if(root==NULL)
	return 0;
	return root->data+getSum(root->left)+getSum(root->right);
}