struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) { return (links[ch - 'a'] != NULL); }

    void put(char ch, Node* node) { links[ch - 'a'] = node; }

    Node* get(char ch) { return links[ch - 'a']; }

    void setEnd() { flag = true; }

    bool isEnd() { return flag; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    string search(string word) {
        Node* node = root;
        string res;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return word;
            }
            res += ch;
            node = node->get(ch);
            if (node->isEnd()) {
                return res;
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie; // object
        for (string word : dictionary) {
            trie.insert(word);
        }

        stringstream ss(sentence); // string split -> sentence to words
        string word, result;
        while (ss >> word) {
            if (!result.empty()) {
                result += " "; // add space
            }
            result += trie.search(
                word); // add shortest string that can be found in the trie
        }
        return result;
    }
};
