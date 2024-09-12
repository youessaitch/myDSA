class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> mp1;
        for(auto it: allowed) mp1[it]++;
        int cnt = 0;
        for(auto it: words){
            unordered_map<char,int> mp2;
            bool ch = true;
            for(auto jt: it){
                mp2[jt]++;
            }

            for(auto jt:mp2){
                if(mp1.find(jt.first)==mp1.end()){
                    ch = false;
                    break;
                }
            }
            if(ch) cnt++;
        }

        return cnt;
    }
};