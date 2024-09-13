class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();
        vector<int> ans;

        vector<int> prefix(n);
        prefix[0]=arr[0];

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]^arr[i];
        }

        for(int i=0;i<m;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            
            int xoro;

            if(l!=0)
            xoro = prefix[l-1]^prefix[r];

            else xoro = prefix[r];

            ans.push_back(xoro);
        }
        return ans;
    }
};