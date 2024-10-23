class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i, int j, string &s, string &t){
        if(i>=n) return n-j;
        if(j>=n) return n-i;

        if(dp[i][j]!=-1) return dp[i][j];

        int insert = 1e9;
        if(s[i] == t[j]){
            insert = 0 + solve(i+1,j+1,s,t);
        }

        int take = min(1 + solve(i+1,j,s,t), 1 + solve(i,j+1,s,t)); 
        return dp[i][j] = min(insert, take);
    }

    int minInsertions(string s) {
        n = s.size();
        string t;
        t = s;
        reverse(t.begin(),t.end());
        dp.resize(n,vector<int>(n,-1));
        return solve(0,0,s,t)/2;
    }
};


    //LCS
    // int solve1(int i, int j, string &s, string &t){
    //     if(i>=n || j>=n) return 0;

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int take1 = 0;
    //     if(s[i] == t[j]){
    //         take1 = 1 + solve1(i+1,j+1,s,t);
    //     }

    //     int take2 = max(solve1(i+1,j,s,t),solve1(i,j+1,s,t));
    //     return dp[i][j] = max(take1, take2);
    // }