class TrieNode{
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode(){
        isWord = false;
        for(int i=0;i<26;i++){
            child[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for(auto it: word){
            int i = it-'a';
            if(!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    
    bool search(string word, bool prefix = false) {
        TrieNode* p = root;
        for(auto it: word){
            int i = it-'a';
            if(!p->child[i]) return false;
            p = p->child[i];
        }
        if(!prefix) return p->isWord;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */