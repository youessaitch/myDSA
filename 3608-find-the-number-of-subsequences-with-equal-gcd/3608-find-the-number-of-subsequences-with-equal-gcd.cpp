class Solution {
public:
    int n;
    int mod = 1e9+7;
    vector<vector<vector<int>>> dp;

    int solve(int i, int first, int second, vector<int> &nums){
        if(i>=n){
            if(first!=0 && second!=0){
                if(first == second) return 1;
            }
            return 0;
        }

        if(dp[i][first][second]!=-1) return dp[i][first][second];

        int skip = solve(i+1, first, second, nums);

        int take1 = solve(i+1, __gcd(first,nums[i])%mod, second, nums);
        int take2 = solve(i+1, first, __gcd(second,nums[i])%mod, nums);

        return dp[i][first][second] = ((skip + take1)%mod + take2) % mod;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        dp.resize(n,vector<vector<int>>(maxi+1,vector<int>(maxi+1,-1)));
        return solve(0,0,0,nums);
    }
};