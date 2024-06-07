// Node structure for Trie
struct Node {
    Node* links[26]; // Array of pointers to child nodes for each alphabet
    bool flag = false; // Flag to mark end of a word

    // Function to check if a key exists in the children nodes
    bool containsKey(char ch) { return (links[ch - 'a'] != NULL); }

    // Function to insert a key and corresponding node in children nodes
    void put(char ch, Node* node) { links[ch - 'a'] = node; }

    // Function to get the child node corresponding to a key
    Node* get(char ch) { return links[ch - 'a']; }

    // Function to mark the current node as the end of a word
    void setEnd() { flag = true; }

    // Function to check if the current node marks the end of a word
    bool isEnd() { return flag; }
};

// Trie class for string operations
class Trie {
private: 
    Node* root; // Root node of the Trie
public:
    // Constructor to initialize the Trie with an empty root node
    Trie() {
        root = new Node();
    }
    
    // Function to insert a word into the Trie
    void insert(string word) {
        Node* node = root; // Start from the root
        for(auto ch: word){
            if(!node->containsKey(ch)){ // If the current node doesn't have the key
                node->put(ch,new Node()); // Create a new node and link it
            }
            node = node->get(ch); // Move to the child node
        }
        node->setEnd(); // Mark the last node as the end of a word
    }
    
    // Function to search for a word in the Trie
    bool search(string word) {
        Node* node = root; // Start from the root
        for(auto ch: word){
            if(!node->containsKey(ch)){ // If the key doesn't exist in the children nodes
                return false; // Word not found
            }
            node = node->get(ch); // Move to the child node
        }
        return node->isEnd(); // Check if the last node marks the end of a word
    }
    
    // Function to check if there is any word in the Trie that starts with a given prefix
    bool startsWith(string prefix) {
        Node* node = root; // Start from the root
        for(auto ch: prefix){
            if(!node->containsKey(ch)){ // If the key doesn't exist in the children nodes
                return false; // Prefix not found
            }
            node = node->get(ch); // Move to the child node
        }
        return true; // Prefix found
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
