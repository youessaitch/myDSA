struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

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
        Trie trie;
        for (string word : dictionary) {
            trie.insert(word);
        }

        stringstream ss(sentence);
        string word, result;
        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += trie.search(word);
        }
        return result;
    }
};

// int main() {
//     Solution sol;
//     vector<string> dictionary = {"cat", "bat", "rat"};
//     string sentence = "the cattle was rattled by the battery";
//     cout << sol.replaceWords(dictionary, sentence) << endl; // "the cat was rat by the bat"
//     return 0;
// }
