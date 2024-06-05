class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> freq(26,1e9);
        vector<int> check(26,0);
        int n = words.size();
        for(int i=0;i<n;i++){
            // unordered_map<char,int> mpp;
            vector<int> count(26,0);
            for(auto ch: words[i]){
                count[ch-'a']++;
            }

            for(int j=0;j<26;j++){
                freq[j] = min(freq[j],count[j]);
            }
        }

        for(int i=0;i<freq.size();i++){
            if(freq[i]==1e9) continue;
            else{
                while(freq[i]!=0){
                ans.push_back(string(1, 'a' + i));
                freq[i]--;
                } 
            }
        }
        return ans;
    }
};