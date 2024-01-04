#include "../Binary Trees/BinaryTreeNode.h"
#include<iostream>
using namespace std;
#include<queue>

class BST {
    // Define the data members
    BinaryTreeNode<int> *root;
    private:
   void insertIntoBST(BinaryTreeNode<int> *root,int data){
     if (root == NULL) {
       this->root = new BinaryTreeNode<int>(data);
       return;
     }
     if (root->data < data) {
       if (root->right != NULL)
         insertIntoBST(root->right, data);
       else {
         BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
         root->right = node;
       }
     } else {
       if (root->left != NULL)
         insertIntoBST(root->left, data);
       else {
         BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
         root->left = node;
       }
     }
   }
    bool searchInBST(BinaryTreeNode<int> *root,int data){
         if(root==NULL)
        return false;
        if(root->data==data)
        return true;
        return searchInBST(root->left,data)||searchInBST(root->right,data);
    }

    void printInBST(BinaryTreeNode<int> *root){
      if(root==NULL)
      return;
      cout<<root->data<<":";
      if(root->left!=NULL)
      cout<<"L:"<<root->left->data<<",";
      if(root->right!=NULL)
      cout<<"R:"<<root->right->data;
      cout<<endl;
      printInBST(root->left);
      printInBST(root->right);
    }

    BinaryTreeNode<int>* minFromRightSubTree(BinaryTreeNode<int> *root){
      if(root==NULL)
      return NULL;
      if (root->left == NULL) {
        BinaryTreeNode<int> *node = root;
        delete root;
        return node;
      }
      return minFromRightSubTree(root->left);
    }
   
    BinaryTreeNode<int>* removeInBST(BinaryTreeNode<int> *node,int data){
        if(node==NULL)
        return NULL;
        if(node->data>data)
        node->left = removeInBST(node->left, data);
        if(node->data<data)
        node->right = removeInBST(node->right, data);

        if(node->left==NULL&&node->right==NULL)
        {
          delete node;
          return NULL;
        }
        else if(node->left==NULL){
            BinaryTreeNode<int> *temp = node->right;
            node->right=NULL;
            delete node;
            return temp;
        }
        else if(root->right==NULL){
          BinaryTreeNode<int> *temp = node->left;
          node->left=NULL;
          delete node;
          return temp;
        }

        else{
          BinaryTreeNode<int> *minNode = node->right;
          while(minNode->left!=NULL)
          minNode =minNode->left;
          node->data= minNode->data;
          node->right = removeInBST(node->right, minNode->data);
          return node;
        }
    }



    // //print LevelWise
    // void printInBST(BinaryTreeNode<int> *root){
    //     if(root==NULL)
    //     return;
    //     queue<BinaryTreeNode<int>*> pendingNodes;
    //     pendingNodes.push(root);
    //     while(pendingNodes.size()!=0){
    //         BinaryTreeNode<int> *curRoot = pendingNodes.front();
    //         cout<<curRoot->data<<":";
    //         if(curRoot->left!=NULL){
    //           cout<<"L:"<<curRoot->left->data<<",";
    //           pendingNodes.push(curRoot->left);
    //         }
    //         if(curRoot->right!=NULL){
    //           cout<<"R:"<<curRoot->right->data;
    //           pendingNodes.push(curRoot->right);
    //         }
    //         cout<<endl;
    //         pendingNodes.pop();
    //     }
    // }
   public:
    BST() { 
        root=NULL;
    }
    ~BST(){
        delete root;
    }

    void remove(int data) { 
        root = removeInBST(root,data);
    }

    void print() { 
        printInBST(root);
    }

    void insert(int data) { 
        insertIntoBST(root,data);
    }

    bool search(int data) {
        searchInBST(root, data);
       
    }
};