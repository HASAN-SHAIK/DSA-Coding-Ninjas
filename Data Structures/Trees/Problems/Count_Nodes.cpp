int getLargeNodeCount(TreeNode<int>* root, int x) {
    // Write your code here
    if(root->children.size()==0&&root->data>x)
    return 1;
    if(root->children.size()==0)
    return 0;
    int ans=0;
    int k;
    for (int i = 0; i < root->children.size(); i++) {
        k=getLargeNodeCount(root->children[i], x);
        ans += k;
    }
    if(root->data>x)
    ans++;
    return ans;
}