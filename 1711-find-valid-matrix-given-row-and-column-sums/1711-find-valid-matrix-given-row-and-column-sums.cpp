class Solution {
public:
    int n,m;
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // 5 0 0
        // 3 3 1
        //  
        n = rowSum.size();
        m = colSum.size();
        vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = min(rowSum[i],colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }

        return ans;
    }
};