template <typename T>
class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(int data){
        this->data = data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};
