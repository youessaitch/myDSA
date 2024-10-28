class Solution {
public:
    int n,m;
    vector<vector<int>> dp;

    // int solve(int i, int j, string &word1, string &word2){
    //     if(j>=m) return n-i;
    //     if(i>=n) return m-j;

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int take = 0;
    //     if(word1[i]==word2[j]){
    //         take = solve(i+1,j+1,word1,word2);
    //     }else{
    //         int ins = 1 + solve(i,j+1,word1,word2);
    //         int del = 1 + solve(i+1,j,word1,word2);
    //         int rep = 1 + solve(i+1,j+1,word1,word2);

    //         take = min({ins,del,rep});
    //     }

    //     return dp[i][j] = take;
    // }

    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        // dp.resize(n+1,vector<int>(m+1,-1));
        // return solve(0,0,word1,word2);
        dp.resize(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] != word2[j-1]){
                    dp[i][j] = min({1+dp[i-1][j],1+dp[i][j-1],1+dp[i-1][j-1]});
                }else{
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }

        return dp[n][m];
    }
};