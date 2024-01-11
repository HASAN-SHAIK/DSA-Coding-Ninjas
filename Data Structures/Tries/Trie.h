#include<string>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode** children;
    bool isTerminal;
    TrieNode(char data){
        this->data = data;
        isTerminal = false;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++)
        children[i]=NULL;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
    ~Trie(){
        for(int i=0;i<26;i++)
        delete root->children[i];
        delete root;
    }
    private:
    void addWord(TrieNode*root,string word){
        //Base case
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index]==NULL){
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        else{
            child = root->children[index];
        }
        addWord(child,word.substr(1));
    }
    public:
    void insertWord(string word){
        addWord(root,word);
    }
   bool getWord(TrieNode*root,string word){
        if(word.size()==0){
            if(root->isTerminal==true)
                return true;
            else
                return false;
        }
        int index = word[0]-'a';
        if(root->children[index]==NULL)
        return false;
        return getWord(root->children[index],word.substr(1));
    }

    bool searchWord(string word){
        return getWord(root,word);
    }
    void removeWord(TrieNode *root,string word){
        //Base case
        if(word.size()==0){
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child = root->children[index];
        if(child==NULL)
        return;
        removeWord(child,word.substr(1));
        //Checking if there are any Children for the child Node
        for(int i=0;i<26;i++){
            if(child->children[i]!=NULL)
            return;
        }
        delete child;
        root->children[index] = NULL;
    }
    void removeWord(string word){
        removeWord(root,word);
    }
};
