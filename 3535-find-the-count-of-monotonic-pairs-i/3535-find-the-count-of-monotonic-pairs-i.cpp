class Solution {
public:
    int n;
    int m = 1e9+7;
    vector<vector<vector<int>>> dp;

    int solve(int idx, int prev1, int prev2, vector<int> &nums){
        if(idx>=n) return 1;

        if(dp[idx][prev1][prev2]!=-1) return dp[idx][prev1][prev2];

        int ans = 0;
        for(int i=0;i<=nums[idx];i++){
            int j = nums[idx]-i;
            if(i>=prev1 && j<=prev2){
                ans = (ans + solve(idx+1,i,j,nums))%m;
            }
        }
        return dp[idx][prev1][prev2] = ans;
    }

    int countOfPairs(vector<int>& nums) {
        n = nums.size();
        dp.resize(n+1,vector<vector<int>>(51,vector<int>(51,-1)));
        return solve(0,0,50,nums);
    }
};