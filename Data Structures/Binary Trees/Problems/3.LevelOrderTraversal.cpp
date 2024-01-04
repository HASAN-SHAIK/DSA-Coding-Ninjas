#include<iostream>
#include "../BinaryTreeNode.h"
#include<queue>
#include<stack>
using namespace std;
#include <math.h>
void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
	queue<BinaryTreeNode<int>*> pendingRoot;
	pendingRoot.push(root);
	int *a,i=0;
	a[0]=root->data;
	while(pendingRoot.size()!=0){
		BinaryTreeNode<int> *root =pendingRoot.front();
		
        if (root->left != NULL) {
        	pendingRoot.push(root->left);
			a[i++]=root->left->data;
        }
		else
		a[i++]=-1;
        if (root->right != NULL) {
            pendingRoot.push(root->right);
			a[i++]=root->right->data;
        }
		else
		a[i++]=-1;
		pendingRoot.pop();
    }
	int n=i,j=0;
        for (int i = 0; i < log2(n); i++) {
			int x= pow(2,i),count=0;
			while(count<x&&j<n){
			if(a[j]!=-1)
            cout << a[j] << " ";
			count++;
			j++;
			}
			cout<<endl;
        }
}

