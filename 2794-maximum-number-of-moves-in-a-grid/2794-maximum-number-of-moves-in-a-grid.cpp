class Solution {
public:
    int n,m;
    bool check(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }

    int dx[4] = {-1,0,1};
    int dy[4] = {1,1,1};

    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>> &grid){
        if(!check(i,j)) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int take = 0;
        for(int k=0;k<3;k++){
            int nr = i + dx[k];
            int nc = j + dy[k];

            if(check(nr,nc) && grid[nr][nc]>grid[i][j]){
                take = max(take,1 + solve(nr,nc,grid));
            }
        }
        
        return dp[i][j] = take;
    }

    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n,vector<int>(m,-1));

        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi, solve(i,0,grid));
        }
        return maxi;
    }
};