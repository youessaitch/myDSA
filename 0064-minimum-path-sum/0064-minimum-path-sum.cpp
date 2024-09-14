class Solution {
public:
    int n,m;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>&grid){
        if(i>=n || j>=m) return 1e9;
        if(i==n-1 && j==m-1) return grid[n-1][m-1];

        if(dp[i][j]!=-1) return dp[i][j];

        int take = 1e9;
        int right = grid[i][j] + solve(i,j+1,grid);
        int down = grid[i][j] + solve(i+1,j,grid);

        return dp[i][j] = min(right,down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return solve(0,0,grid);
        // return dp[0][0];
    }
};