#include<iostream>
#include<string>
#include<vector>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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

    bool add(TrieNode *root, string word) {
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
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }
    string searchWord(TrieNode*root,string word){
        if(word.size()==0){
            if(root->isTerminal ==true)
            return word;
            else
            return "m";    
        }
        int index =  word[0]-'a';
        TrieNode* child = root->children[index];
        if (child == NULL) {
            for(int i=0;i<26;i++){
                if(root->children[i]!=NULL)
                return "-1";
            }
            return word;
        }
        return searchWord(child, word.substr(1));
    }
    string searchWord(string word){
        return searchWord(root, word);
    }

    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
        // Write your code here
       Trie root;
        for(int i=0;i<words.size();i++){
            root.add(words[i]);
        }

        for(int i=0;i<words.size();i++){
            string word = words[i];
            reverse(word.begin(),word.end());
            // cout<<word<<endl;
            string w = root.searchWord(word);
            if(w.size()==word.size())
            return false;
            if(w[0]=='-1')
            return false;
            if(w.size()==0)
            return true;
            string revword = w;
            reverse(w.begin(),w.end());
            if(w== revword)
            return true;
            }
        return false;
    }
};