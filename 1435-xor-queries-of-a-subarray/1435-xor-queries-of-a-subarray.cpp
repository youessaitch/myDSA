class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();
        vector<int> ans;

        for(int i=0;i<m;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int xoro = 0;
            for(int j=l;j<=r;j++){
                xoro ^= arr[j];
            }
            ans.push_back(xoro);
        }
        return ans;
    }
};