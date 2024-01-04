#include<iostream>
#include "../BinaryTreeNode.h"
#include<queue>
#include<stack>
using namespace std;

pair<int,bool> helperFunction(BinaryTreeNode<int>*root){
	if(root==NULL)
	return {0,true};
	pair<int,int> ans= helperFunction(root->left);
	pair<int,int> ans1 = helperFunction(root->right);
	pair<int,int> p;
	p.first = 1+ max(ans.first,ans1.first);
	if(ans.second==false||ans1.second==false||abs(ans.first-ans1.first)>1)
	p.second = false;
	else
	p.second=true;
	return p;
}