#include<iostream>
#include "../BinaryTreeNode.h"
#include<queue>
#include<stack>
#include "../LinkedList/Node.h"

using namespace std;
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL)
	return {};
	queue<BinaryTreeNode<int>*> pendingRoot;
	pendingRoot.push(root);
	BinaryTreeNode<int> *sample = new BinaryTreeNode<int>(-1);
	pendingRoot.push(sample);
	vector<Node<int>*> ans;
	while(pendingRoot.size()!=0){
		Node<int> *first = new Node<int>(-1);
		Node<int>* head= first;
		while(pendingRoot.front()->data!=-1){
			BinaryTreeNode<int> *root =pendingRoot.front();
			Node<int> *sample = new Node<int> (root->data);
			first->next = sample;
			first=first->next;
			if (root->left != NULL) {
        		pendingRoot.push(root->left);
        	}
        	if (root->right != NULL) {
            	pendingRoot.push(root->right);
        	}
			pendingRoot.pop();
	}
		pendingRoot.pop();
		ans.push_back(head->next);
                if (pendingRoot.size() != 0) {
                        BinaryTreeNode<int> *sample =
                            new BinaryTreeNode<int>(-1);
                        pendingRoot.push(sample);
                }
    }
	return ans;
}