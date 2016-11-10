/*

Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

https://leetcode.com/problems/implement-trie-prefix-tree/

*/

class TrieNode {
public:
    TrieNode *children[26];
    int count;
    // Initialize your data structure here.
    TrieNode() {
        memset(children,0,sizeof(children));
        count = 0;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *curr = root;
        for(int i=0;i<word.length();i++){
            int ch = word[i]-'a';
            if(curr->children[ch] == NULL){
                curr->children[ch] = new TrieNode(); 
            }
            curr = curr->children[ch];
        }
        curr->count++;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *curr = root;
        for(int i=0;i<word.length();i++){
            int ch = word[i]-'a';
            if(curr->children[ch] == NULL)
                return false;
            curr = curr->children[ch];
        }
        return curr->count > 0;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * curr = root;
        for(int i=0;i<prefix.length();i++){
            int ch = prefix[i] - 'a';
            if(curr->children[ch] == NULL)
                return false;
            curr = curr->children[ch];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");