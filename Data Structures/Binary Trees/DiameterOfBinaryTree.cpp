#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>
using namespace std;

int height(BinaryTreeNode<int>* root) {
    // Write our code here
	if(root==NULL)
	return 0;
	return 1+max(height(root->left),height(root->right));
}



int diameterOfTree(BinaryTreeNode<int> * root){
    if(root==NULL)
    return 0;
    int a  = height(root->left)+height(root->right);
    int b = diameterOfTree(root->left);
    int c =  diameterOfTree(root->right);
    return max(a,max(b,c));
}

pair<int,int> heightDiameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> lheightDiameter = heightDiameter(root->left);
    pair<int,int> rheightDiameter = heightDiameter(root->right);
    int lh=lheightDiameter.first;
    int ld=lheightDiameter.second;
    int rh=rheightDiameter.first;
    int rd=rheightDiameter.second;
    pair<int,int> p;
    p.first = 1+max(rh,lh);
    p.second = max(lh+rh,max(rd,ld));
    return p;
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

int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    pair<int,int> ans= heightDiameter(root);
    cout<<"Height: "<<ans.first<<endl;
    cout<<"Diameter: "<<ans.second<<endl;
    delete root;
}
