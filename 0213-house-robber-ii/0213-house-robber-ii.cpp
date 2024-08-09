class Solution {
public:
    int n;
    int solve(int i, vector<int> &nums, vector<int> &dp){
        if(i>=nums.size()) return 0;;

        if(dp[i]!=-1) return dp[i];

        int loot = nums[i] + solve(i+2,nums,dp);
        int skip = solve(i+1,nums,dp);

        return dp[i] = max(loot,skip);
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        vector<int> a(nums.begin(),nums.end()-1);
        vector<int> b(nums.begin()+1,nums.end());
        int ans1 = solve(0,a,dp1);
        int ans2 = solve(0,b,dp2);
        return max(ans1,ans2);
    }
};