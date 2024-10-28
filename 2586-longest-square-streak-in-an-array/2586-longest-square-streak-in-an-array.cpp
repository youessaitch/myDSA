class Solution {
public:
    // int n;
    // vector<vector<int>> dp;

    // int solve(int i, int prev, vector<int>&nums){
    //     if(i>=n) return 0;

    //     if(dp[i][prev+1]!=-1) return dp[i][prev+1];

    //     int take = 0;
    //     if(prev==-1 || nums[i] == nums[prev]*nums[prev]){
    //         take = 1+solve(i+1,i,nums);
    //     }

    //     int notTake = solve(i+1,prev,nums);

    //     return dp[i][prev+1] = max(take, notTake);
    // }

    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        // dp.resize(n,vector<int>(n+1,-1));
        int ans = 0;
        for(int i=0;i<n;i++){
            int temp = sqrt(nums[i]);
            if(temp*temp == nums[i] && mpp.find(temp)!=mpp.end()){
                mpp[nums[i]] = mpp[temp]+1;
                ans = max(ans,mpp[nums[i]]);
            }else{
                mpp[nums[i]] = 1;
            }
        }
        if(ans <= 1) return -1;
        return ans;
    }
};