class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int countSquares(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));

        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=0;i<=m;i++) dp[0][i]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mat[i-1][j-1] == 1){
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }else{
                    dp[i][j]=0;
                }
            }
        }

        int ans = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans += dp[i][j];
            }
        }

        return ans;
    }
};