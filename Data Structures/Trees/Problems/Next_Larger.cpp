TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
    TreeNode<int>* nextLarger=NULL;
     if(root->data>x&&nextLarger==NULL)
        nextLarger=root;
        else if(root->data>x&&nextLarger->data>root->data)
        nextLarger=root;
        else{
            for(int i=0;i<root->children.size();i++){
                nextLarger = getNextLargerElement(root->children[i], x);
            }
        }
        return nextLarger;
}