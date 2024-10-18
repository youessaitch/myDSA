class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_map<string,int> mpp;
        for(auto &it: wordList) mpp[it]++;

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;

            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(int c = 'a'; c<='z';c++){
                    word[i] = c;
                    if(mpp.find(word)!=mpp.end()){
                        mpp[word]--;
                        if(mpp[word]==0) mpp.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = original;
            }
            
        }

        return 0;
    }
};