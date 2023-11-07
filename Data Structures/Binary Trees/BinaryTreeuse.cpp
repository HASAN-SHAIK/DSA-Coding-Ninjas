#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>
#include<stack>
using namespace std;

template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

BinaryTreeNode<int>* takeInput(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    BinaryTreeNode<int> *left = takeInput();
    BinaryTreeNode<int> *right = takeInput();
    root->left = left;
    root->right = right;
    return root;
}

BinaryTreeNode<int>* takeInputLevelWise(){
    queue<BinaryTreeNode<int>*> pendingNodes;
    int data;
    cout<<"Enter the Root Data"<<endl;
    cin>>data;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int> *root = pendingNodes.front();
        cout<<"Enter LeftChild Data "<<root->data<<endl;
        int lchildData;
        cin>>lchildData;
        if(lchildData==-1)
        root->left=NULL;
        else{
            BinaryTreeNode<int> *lchild = new BinaryTreeNode<int>(lchildData);
            pendingNodes.push(lchild);
            root->left = lchild;
        }
        cout<<"Enter Right Child Data of "<<root->data<<endl;
        int rchildData;
        cin>>rchildData;
        if(rchildData==-1)
        root->right=NULL;
        else{
            BinaryTreeNode<int> *rchild = new BinaryTreeNode<int>(rchildData);
            pendingNodes.push(rchild);
            root->right = rchild;
        }
        pendingNodes.pop();
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0){
		BinaryTreeNode<int> *root = pendingNodes.front();
		cout<<root->data<<":";
		if(root->left==NULL)
		cout<<"L:-1,";
        else {
            cout << "L:" << root->left->data << ",";
			pendingNodes.push(root->left);
        }
        if(root->right==NULL)
			cout<<"R:-1\n";
            else {
            cout << "R:" << root->right->data << endl;
			pendingNodes.push(root->right);
                }
                pendingNodes.pop();
	}
}

void printTree(BinaryTreeNode<int> *root){
    if(root==NULL)
    return;
    cout<<root->data<<":";
    if(root->left!=NULL)
    cout<<"L"<<root->left->data;
    if(root->right!=NULL)
    cout<<"R"<<root->right->data;
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

int countNodes(BinaryTreeNode<int> *root){
    if(root==NULL)
    return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    if(root==NULL)
    return 0;
    if(root->data==x)
    return true;
    return isNodePresent(root->left, x) || isNodePresent(root->right, x);
}

int height(BinaryTreeNode<int>* root) {
    // Write our code here
	if(root==NULL)
	return 0;
	return 1+max(height(root->left),height(root->right));
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
	if(root==NULL)
	return;
	mirrorBinaryTree(root->left);
	mirrorBinaryTree(root->right);
	BinaryTreeNode<int>* temp= root->left;
	root->left = root->right;
	root->right = temp;
}

#include<stack>
vector<int> preOrder(TreeNode<int> * root){
    // // Recursion
    // if(root==NULL)
    // return {};
    // vector<int> ans;
    // ans.push_back(root->data);
    // vector<int> left = preOrder(root->left);
    // vector<int> right = preOrder(root->right);
    // for(int i=0;i<left.size();i++)
    // ans.push_back(left[i]);
    // for(int j=0;j<right.size();j++)
    // ans.push_back(right[j]);
    // return ans;

    //Using Stack
    vector<int> ans;
    stack<TreeNode<int>*> s;
    s.push(root);
    while(s.size()!=0){
        TreeNode<int> *root = s.top();
        s.pop();
        ans.push_back(root->data);
        if(root->right!=NULL)
        s.push(root->right);
        if(root->left!=NULL)
        s.push(root->left);
    }
    return ans;
}

//Traversals
void postOrder(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root==NULL)
	return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}



void inorder(BinaryTreeNode<int> *root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}



int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    inorder(root);
}
