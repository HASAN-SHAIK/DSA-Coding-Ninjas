#include <limits.h>
#include "../Binary Trees/BinaryTreeNode.h"
#include<iostream>
using namespace std;
//Method 1
int minimum(BinaryTreeNode<int> *root){
	if(root==NULL)
	return INT_MAX;
	return min(root->data,min(minimum(root->left),minimum(root->right)));
}

int maximum(BinaryTreeNode<int> *root){
	if(root==NULL)
	return INT_MIN;
	return max(root->data,max(maximum(root->left),maximum(root->right)));
}

bool isBST1(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root==NULL)
	return true;
	int rightmin = minimum(root->right);
	int leftmax = maximum(root->left);
	bool output = root->data > leftmax && root->data <= rightmin && (root->left!=NULL&&root->data>root->left->data) && (root->right!=NULL&&root->data<=root->right->data);
	return output;
}

//Method 2: Using Class
class isBSTReturn{
	public:
	int mini,maxi;
	bool isBST;
};
isBSTReturn helper2(BinaryTreeNode<int> *root){
	if(root==NULL){
		isBSTReturn ans;
		ans.mini = INT_MAX	;
		ans.maxi = INT_MIN;
		ans.isBST=true;
		return ans;
	}
	isBSTReturn left = helper2(root->left);
	isBSTReturn right = helper2(root->right);
	int minimum = min(root->data,min(left.mini,right.mini));
	int maximum = max(root->data,max(left.maxi,right.maxi));
	isBSTReturn ans;
	ans.mini = minimum;
	ans.maxi = maximum;
	ans.isBST = root->data>left.maxi&&root->data<=right.mini&& left.isBST&&right.isBST;
	return ans;
}
bool isBST2(BinaryTreeNode<int> *root) {
	return helper2(root).isBST;
}


//Method 3: Using lower and Upper Limits :Top Down approach
bool helper3(BinaryTreeNode<int> *root,int min=INT_MIN,int max=INT_MAX){
	if(root==NULL)
	return true;
	if(root->data<=min||root->data>max)
	return false;
	int leftmax=root->data;
	int rightmin = root->data;
	return helper3(root->left,min,leftmax) && helper3(root->right,rightmin,max);

}
bool isBST3(BinaryTreeNode<int> *root) {
	return helper3(root);
}