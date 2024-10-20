class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length()<t.length()) return "";
        int n = s.size();
        int m = t.size();

        int ans = 1e9;
        unordered_map<char,int> mps;
        unordered_map<char,int> mpt;
        for(auto it: t) mpt[it]++;
        int i=0,j=0;
        string res = "";
        int ind = -1;

        while(j<n){
            mps[s[j]]++;

            while(1){
                if(i>j) break;
                bool ch = true;
                for(auto it: mpt){
                    if(mps[it.first]<it.second){
                        ch = false;
                        break;
                    }
                }
                if(ch){
                    if(j-i+1 < ans){
                        ans = j-i+1;
                        // res = s.substr(i,j-i+1);
                        ind = i;
                    }
                    mps[s[i]]--;
                    if(mps[s[i]]==0) mps.erase(s[i]);
                    i++;
                }else break;
            }

            // cout<<i<<" "<<j<<endl;

            // if(j-i+1 < ans){
            //     ans = j-i+1;
            //     res = s.substr(i,j-i+1);
            // }

            // cout<<ans<<endl;
            j++;
        }
        if(ind == -1) return "";
        res = s.substr(ind,ans);
        return res;
    }
};