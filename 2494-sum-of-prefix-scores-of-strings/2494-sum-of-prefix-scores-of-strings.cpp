struct Trie {
    int score = 0;
    Trie* children[26];
};

class Solution {
public:

    Trie* getTrie() {
        Trie* newNode = new Trie();
        for(int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }
        newNode->score = 0;
        return newNode;
    }

    void insert(string& word, Trie* root) {
        Trie* p = root;

        for(char &ch : word) {
            int idx = ch - 'a';

            if(!p->children[idx]) {
                p->children[idx] = getTrie();
            }

            p->children[idx]->score += 1;
            p = p->children[idx];
        }
    }

    int getScore(string& word, Trie* root) {
        Trie* p = root; //"abc"
        int score = 0;

        for(char &ch : word) {
            int idx = ch - 'a';
            score += p->children[idx]->score;

            p = p->children[idx]; // now i am at "b" wala node
        }

        return score;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();

        Trie* root = getTrie();
        for(string &word : words) {
            insert(word, root);
        }

        vector<int> result(n);
        //result[i] = sum of scores of prefixes of words[i]
        for(int i = 0; i < n; i++) {
            result[i] = getScore(words[i], root);
        }

        return result;
    }
};