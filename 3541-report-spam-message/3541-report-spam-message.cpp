class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int n = message.size();
        int m = bannedWords.size();

        unordered_map<string,int> mpp;
        for(auto it: bannedWords) mpp[it]++;

        int cnt = 0;
        for(auto it: message){
            if(mpp.find(it)!=mpp.end()){
                cnt++;
            }
            if(cnt >=2 ) return true;
        }

        return false;
    }
};