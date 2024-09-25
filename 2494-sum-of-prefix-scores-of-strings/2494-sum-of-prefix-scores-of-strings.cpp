struct Trie{
    int score;
    Trie* children[26];
    Trie(){
        score = 0;
        memset(children,0,sizeof(children));
    }

    //insert a word into trie
    void add(string &s, int i){
        if(i) score++;
        if(i == s.size()) return;
        if(!children[s[i]-'a']) children[s[i]-'a'] = new Trie();
        children[s[i]-'a']->add(s,i+1);
    }

    int dfs(string &s, int i){
        if(i==s.size()) return score;
        return score + children[s[i]-'a']->dfs(s,i+1);
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> ans;
        Trie* trie = new Trie();
        for(auto it: words) trie->add(it,0);
        for(auto it: words) ans.push_back(trie->dfs(it,0));
        return ans;
    }
};