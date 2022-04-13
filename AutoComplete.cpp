// Given n number of words and an incomplete word w. You need to auto-complete that word w.
// That means, find and print all the possible words which can be formed using the incomplete word w.
// Note : Order of words does not matter.

#include <iostream>
#include <string>
#include <vector>
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
    
     TrieNode* search(TrieNode *root,string word){
        
        if(word.size()==0){
            return root;
        }
        
        int index=word[0] -'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        	TrieNode* small=search(child,word.substr(1));
            return small;
        }
        else
            return NULL;
    }
    
 
	 TrieNode*  search(string word) {
        // Write your code here
         return search(root,word);
     }
	void print(TrieNode *root,string word){
        if (root->isTerminal){
            cout << word << endl;
        }
        for (int i = 0 ; i < 26 ; i++){
            if (root->children[i] != NULL){
                char c = 'a' + i;
                print(root->children[i] , word + c);
            }
        }
    }
    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        for(int i=0;i<input.size();i++)
            insertWord(input[i]);
        TrieNode *s = search(pattern);
        if (s == NULL){
            return;
        }
        print(s , pattern);
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}