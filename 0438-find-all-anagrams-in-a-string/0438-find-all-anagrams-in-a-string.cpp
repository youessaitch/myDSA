class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        map<char,int> mpp;
        for(auto it: p) mpp[it]++;

        if(n<m) return {};

        map<char,int> mps;
        int i=0, j=m-1;
        for(int j=0;j<m;j++) mps[s[j]]++;

        vector<int> ans;

        while(j<n){
            if(mps == mpp) ans.push_back(i);

            j++;
            mps[s[j]]++;
            mps[s[i]]--;
            if(mps[s[i]]==0) mps.erase(s[i]);
            i++;
        }

        return ans;
    }
};