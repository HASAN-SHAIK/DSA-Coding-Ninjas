void  replacewithDepth(TreeNode<int> *root,int d){
    root->data=d;
    for(int i=0;i<root->children.size();i++){
        replacewithDepth(root->children[i],d+1);
    }
}

void replaceWithDepthValue(TreeNode<int>* root) {
    // Write your code here
    replacewithDepth(root,0);
}