class Solution {
public:
int solve(int i, vector<int> &coins, int amount, vector<vector<int>> &dp){
        int n = coins.size();
        
        if(amount == 0){
            return 0;
        }

        if(i<0 || amount<0){
            return 1e9;
        }
          
        if(dp[i][amount]!=-1) return dp[i][amount];

        int take = 1e9;
        if(coins[i] <= amount){
            take = 1 + solve(i,coins,amount-coins[i],dp);
        }

        int notTake = solve(i-1,coins,amount,dp);

        return dp[i][amount] = min(take,notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount == 0) return 0;
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans = solve(n-1,coins,amount,dp);
        if(ans==0 || ans>=1e9) return -1;
        return ans;
    }
};