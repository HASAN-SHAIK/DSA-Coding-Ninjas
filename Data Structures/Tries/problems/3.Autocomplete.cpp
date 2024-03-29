#include<iostream>
#include<string>
#include<vector>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    void printWords(TrieNode*root, string word,string str ){
        if (word.size() == 0 && root->isTerminal == true) {
            // cout<<"sample\n";
            cout << str << endl;
        }
        // cout<<str<<endl;
        if(word.size()==0){
            for(int i=0;i<26;i++){
                if(root->children[i]!=NULL){
                    printWords(root->children[i], word, str+root->children[i]->data);
                }
            }
        }
        else{
            int index = word[0]-'a';
            str+=word[0];
            if(root->children[index]==NULL)
            return;
            printWords(root->children[index],word.substr(1),str);
        }
    }

    void printWords(string word){
        printWords(root, word, "");
    }

    void autoComplete(vector<string> words, string pattern) {
        // Write your code here
        Trie root;
        for(int i=0;i<words.size();i++){
            root.insertWord(words[i]);
        }
        root.printWords(pattern);
    }
};