class Solution {
public:
    bool check(int i, int j, int m, int n){
        return i>=0 && i<m && j>=0 && j<n;
    }

    int dfs(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(!check(i,j,m,n)) return 0;

        if(i==m-1 && j==n-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int bottom = dfs(i+1,j,m,n,dp);
        int right = dfs(i,j+1,m,n,dp);

        return dp[i][j] = bottom + right;

    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = dfs(0,0,m,n,dp);
        return ans;
    }
};