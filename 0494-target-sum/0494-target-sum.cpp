class Solution {
public:
    int n;
    int offset = 1000;
    vector<vector<int>> dp;
    int solve(int i, int sum, vector<int> &nums, int target){
        if(i>=n){
            if(sum == target){
                return 1;
            }
            return 0;
        }

        if(dp[i][sum+offset]!=-1) return dp[i][sum+offset];

        return dp[i][sum+offset] = solve(i+1, sum + nums[i], nums, target) + solve(i+1, sum - nums[i], nums,target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        dp.resize(n,vector<int>(2*offset+1,-1));
        // int sum = 0;
        return solve(0,0,nums,target);
    }
};