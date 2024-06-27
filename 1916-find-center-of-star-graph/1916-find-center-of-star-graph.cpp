class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mpp;
        int ans = -1;
        for(auto it: edges){
            mpp[it[0]]++;
            mpp[it[1]]++;
        }
        for(auto it: mpp){
            if(it.second>1){
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};