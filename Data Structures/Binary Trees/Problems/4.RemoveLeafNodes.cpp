#include<iostream>
#include "../BinaryTreeNode.h"
#include<queue>
#include<stack>
using namespace std;
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL||(root->left==NULL&&root->right==NULL))
	return NULL;
        if (root->left != NULL) {
        if (root->left->left == NULL && root->left->right == NULL)
          root->left = NULL;
        }
        if (root->right !=NULL) {
        if (root->right->left == NULL && root->right->right == NULL)
          root->right = NULL;
        }
        removeLeafNodes(root->left);
	removeLeafNodes(root->right);
	return root;
}