//Brute Force
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int>* max= root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* max2=maxDataNode(root->children[i]);
        if(max->data<max2->data)
        max=max2;
    }
    return max;
    }

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

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here

   FirstSecondMaxNode<int> *ans = getfirstSec(root);
   return ans->second;
}



//Optimal
template <typename T>
class FirstSecondMaxNode{
    public:
    TreeNode<T>* first;
    TreeNode<T> *second; 
    FirstSecondMaxNode(TreeNode<int>*first,TreeNode<int>*second){
        this->first = first;
        this->second= second;
    }
};


 FirstSecondMaxNode<int>* getfirstSec(TreeNode<int> *root){
    //Set root node as larger and second as NULL
   FirstSecondMaxNode<int> *ans = new FirstSecondMaxNode<int>(root,NULL);

    //For each child check call getfirstsec method and store it in a fsNode variable
    for(int i=0;i<root->children.size();i++){
        FirstSecondMaxNode<int>* fsnode =getfirstSec(root->children[i]);
         //Compare the fsnode and firstsec variable swap accordingly
         if(ans->second == NULL){
             /*Check whether the fsNode has first and second largest number 
             if yes compare the first of ans with fsnode first and second 
             else compare with fsNode and ans node first*/
             if(fsnode ->second==NULL ){
                 if(fsnode->first >ans->first){
                    ans->second = ans ->first;
                    ans->first = fsnode->first;
                 }
                 else{
                     if(fsnode->second > ans->first){
                        ans->first = fsnode->first;
                        ans->second = fsnode->second;
                     }
                     else if(fsnode->first<ans->first){
                         ans->second = fsnode->first;
                     }
                     else{
                         ans->second = ans->first;
                         ans->first = fsnode->first;
                     }
                 }
             }
         }
    }
       
    //return firstsec variable
    return ans; 
}