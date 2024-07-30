class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<vector<int>> dp;

    int solve(int i, int line){
        if(i==0 || i==line) return 1;

        if(dp[i][line]!=-1) return dp[i][line];

        int ans = solve(i-1,line-1) + solve(i,line-1);

        return dp[i][line] = ans;
    }

    vector<vector<int>> generate(int numRows) {
        dp.resize(numRows,vector<int>(numRows,-1));
        ans.resize(numRows);

        for (int line = 0; line < numRows; ++line) {
            for (int i = 0; i <= line; ++i) {
                ans[line].push_back(solve(i, line));
            }
        }

        return ans;
    }
};