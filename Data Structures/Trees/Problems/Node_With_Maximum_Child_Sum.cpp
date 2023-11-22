#include <utility>
pair<TreeNode<int>*,int> maxNode(TreeNode<int>* root){
    pair<TreeNode<int>*,int> max;
    int sum=root->data;
    for(int i=0;i<root->children.size();i++)
        sum+=root->children[i]->data;
    max.second = sum;
    max.first = root;
    for(int i=0;i<root->children.size();i++){
        pair<TreeNode<int>*,int> k= maxNode(root->children[i]);
        if(k.second>max.second)
        {
            max.first = k.first;
            max.second = k.second;
        }
    }
    return max;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    pair<TreeNode<int>*,int> max= maxNode(root);
    return max.first;
}