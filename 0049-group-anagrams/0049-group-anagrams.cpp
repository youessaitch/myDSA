class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();
        map<string,vector<int>> mpp;

        for(int i=0;i<n;i++){
            auto t = s[i];
            sort(t.begin(),t.end());
            mpp[t].push_back(i);
        }

        vector<vector<string>> ans;
        for(auto it: mpp){
            auto v = it.second;
            int m = v.size();
            vector<string> temp;
            for(int i=0;i<v.size();i++){
                temp.push_back(s[v[i]]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};