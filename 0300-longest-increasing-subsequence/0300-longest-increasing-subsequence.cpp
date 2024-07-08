class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int solve(int i, int prev, vector<int> &nums){
        if(i>=n) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int take = 0;
        if(prev == -1 || nums[i]>nums[prev]){
            take = 1+solve(i+1,i,nums);
        }

        int notTake = solve(i+1,prev,nums);

        return dp[i][prev+1] = max(take,notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.resize(n,vector<int>(n,-1));
        int ans = solve(0,-1,nums);
        return ans;
    }
};