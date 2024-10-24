class Solution {
public:
    int n, m;

    bool check(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int ans = 0;

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};

    vector<vector<int>> dp;

    int dfs(int i, int j, vector<vector<int>> &mat){
        if(!check(i,j)) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int maxi = 1;
        for(int k=0;k<4;k++){
            int nr = i+dx[k];
            int nc = j+dy[k];
            if(check(nr,nc) && mat[nr][nc]>mat[i][j]){
                maxi = max(maxi,1 + dfs(nr,nc,mat));
            }
        }

        return dp[i][j] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        dp.resize(n,vector<int>(m,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,dfs(i,j,mat));
            }
        }

        return ans;

    }
};