#include<stack>
#include<queue>
#include<iostream>
#include "../BinaryTreeNode.h"
#include<queue>
#include<stack>
using namespace std;
void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
	queue<BinaryTreeNode<int>*> pendingRoot;
	pendingRoot.push(root);
	BinaryTreeNode<int> *sample = new BinaryTreeNode<int>(-1);
	pendingRoot.push(sample);
	bool stk = false;
	while(pendingRoot.size()!=0){
		stack<BinaryTreeNode<int>*> stak;
		while(pendingRoot.front()->data!=-1){
			BinaryTreeNode<int> *root =pendingRoot.front();
			if(stk==false){
				cout<<root->data<<" ";
			if (root->left != NULL) {
        		pendingRoot.push(root->left);
        	}
        	if (root->right != NULL) {
            	pendingRoot.push(root->right);
        	}
			}
			else{
				stak.push(root);
				if (root->left != NULL) {
        			pendingRoot.push(root->left);
        		}
        		if (root->right != NULL) {
            		pendingRoot.push(root->right);
        		}
			}
			pendingRoot.pop();
	}
		pendingRoot.pop();
		if(stk == false)
		stk=true;
        while(stak.size()!=0){
			cout<<stak.top()->data<<" ";
			stak.pop();
			stk=false;
		}
		cout<<endl;
		if (pendingRoot.size() != 0) {
            BinaryTreeNode<int> *sample =
            new BinaryTreeNode<int>(-1);
            pendingRoot.push(sample);
        }
    }
}