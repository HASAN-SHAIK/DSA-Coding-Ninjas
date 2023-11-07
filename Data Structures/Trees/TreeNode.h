#include<vector>
#include<queue>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(){
        takeInputLevelWise();
    }
    TreeNode(T data){
        this->data=data;
    }


    //Take input levelwise
    TreeNode<int>* takeInputLevelWise(){
    queue<TreeNode<int>*> pendingNodes;
    int rootData;
    cout<<"Enter Root Node data"<<endl;
    cin>>rootData;
    TreeNode<int> *root= new TreeNode<int>(rootData);
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter Number of children for "<<front->data<<endl;
        int children;
        cin>>children;
        for(int i=0;i<children;i++){
            int childData;
            cout<<"Enter the data of child"<<endl;
            cin>>childData;
            TreeNode<int> * child= new TreeNode<int> (childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
    }

    //Print Tree Level Wise
    void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int> * front = pendingNodes.front();
        cout<<front->data<<":";
        pendingNodes.pop();
        int size=front->children.size();
        for(int i=0;i<size;i++){
            pendingNodes.push(front->children[i]);
            if(i==size-1)
            cout<<front->children[i]->data;
            else
            cout<<front->children[i]->data<<",";
        }
        cout<<endl;
    }
    }

    //To Find sum of Nodes
    int sumOfNodes(TreeNode<int>* root) {
    int sum=root->data;
    for(int i=0;i<root->children.size();i++)
    sum+=sumOfNodes(root->children[i]);
    return sum;
    }

    //To Find Max Node
    TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int>* max= root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* max2=maxDataNode(root->children[i])->d;
        if(max->data<max2->data)
        max=max2;
    }
    return max;
    }

    //Height of the tree
    int getHeight(TreeNode<int>* root) {
    if(root->children.size()==0)
    return 1;
    int ans=1;
    int h;
    for(int i=0;i<root->children.size();i++){
        h= 1+getHeight(root->children[i]);
        if(h>ans)
        ans=h;
    }
    return ans;
    }

    //No of Leafs of a Tree
    int getLeafNodeCount(TreeNode<int>* root) {
    if(root->children.size()==0)
    return 1;
    int ans=0;
    for (int i = 0; i < root->children.size(); i++) {
    int k = getLeafNodeCount(root->children[i]);
    ans += k;
    }
    return ans;
    }

    //Print preorder
    void printPreOrder(TreeNode<int>* root) {
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    printPreOrder(root->children[i]);

    }

    //Print Postorder
    void printPostOrder(TreeNode<int>* root) {
    if(root==NULL)
    return;
    for(int i=0;i<root->children.size();i++)
    printPostOrder(root->children[i]);
    cout<<root->data<<" ";
    }

    ~TreeNode(){
        for(int i=0;i<children.size();i++)
        delete children[i];
    }
};

