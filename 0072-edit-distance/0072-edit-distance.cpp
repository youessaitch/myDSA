class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(int i, int j, string &word1, string &word2){
        if(i>=n) return m-j;
        if(j>=m) return n-i;

        if(dp[i][j]!=-1) return dp[i][j];
        
        int take = 0;
        int notTake = 0;
        if(word1[i]==word2[j]){
            take = solve(i+1,j+1,word1,word2);
        }else{
            int insertOp = 1 + solve(i,j+1, word1, word2);
            int deleteOp = 1 + solve(i+1,j, word1, word2); 
            int replaceOp = 1 + solve(i+1,j+1, word1, word2); 

            notTake = min(insertOp,min(deleteOp,replaceOp));
        }
        return dp[i][j] = take + notTake;
    }

    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(0,0,word1,word2);
    }
};