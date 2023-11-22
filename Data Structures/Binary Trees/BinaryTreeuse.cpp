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

int diameterOfTree(BinaryTreeNode<int> * root){
    if(root==NULL)
    return 0;
    int a  = height(root);
    int b = diameterOfTree(root->left);
    int c =  diameterOfTree(root->right);
    return max(a,max(b,c));
}

BinaryTreeNode<int>* constructTree(int *instart,int *inend,int *prestart,int *preend){
	if(instart>inend)
	return NULL;
	if(prestart==preend)
	return new BinaryTreeNode<int>(preend[0]);
	if(instart==inend)
	return new BinaryTreeNode<int>(instart[0]);
	

	BinaryTreeNode<int> *root= new BinaryTreeNode<int>(prestart[0]);
	//Left Tree
	int count=0;
	int *linstart = instart;
	
	while(instart[0]!=root->data){
		instart++;
		count++;
	}
	int *linend=instart-1;
	int *lprestart = prestart+1;
        while (count > 0) {
                prestart++;
                count--;
        }
	int *lpreend = prestart;
	root->left = constructTree(linstart, linend, lprestart, lpreend);
	
	//Right Tree
	int *rinstart = linend+2;
	int *rinend = inend;
	int *rpreend = preend;
	int *rprestart = lpreend+1;
	root->right = constructTree(rinstart,rinend,rprestart,rpreend);

	return root;
}
BinaryTreeNode<int>* buildTreeUsingPreorderInorder(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
	return constructTree(inorder,inorder+inLength-1,preorder,preorder+preLength-1);
}

BinaryTreeNode<int> * buildTreeHelper(int *poststart,int *postend,int*instart,int*inend){
	if(instart>inend)
	return NULL;
	BinaryTreeNode<int> *root= new BinaryTreeNode<int>(postend[0]);
	int *linstart = instart;
	int *lpoststart = poststart;
        while (root->data != instart[0]) {
        poststart++;
        instart++;
        }
        int *linend = instart-1;
	int *lpostend=poststart-1;
	int *rinstart= instart+1;
	int *rinend = inend;
	int *rpoststart = poststart;
	int *rpostend = postend-1;
	root->left = buildTreeHelper(lpoststart,lpostend,linstart,linend);
	root->right = buildTreeHelper(rpoststart,rpostend,rinstart,rinend);
	return root;
}

BinaryTreeNode<int>* buildTreeUsingPostorderInorder(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
	return buildTreeHelper(postorder,postorder+postLength-1,inorder,inorder+inLength-1);
}

int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    cout<<"DIameter: "<<diameterOfTree(root);
}
