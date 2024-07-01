class Solution {
public:

    int n;
    int dp[1001][1003]; //index, difference
    //NOTE: diff can be 0<=diff<=500, but it can be negative too and we cant give negative indices to the dp so lets add a constant here say 502 => 501+502 = 1003
    int solve(int i, int d, vector<int> &nums){
        if(i < 0 ) return 0;

        if(dp[i][d + 501] != -1) return dp[i][d + 501]; //add constant here too to avoid negative indices, answer wont change

        int ans = 0;

        for(int k=i-1; k>=0; k--){
            if(nums[i]-nums[k] == d){
                ans = max(ans,1+solve(k,d,nums));
            }
        }
        return dp[i][d + 501] = ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        memset(dp,-1,sizeof(dp));

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d = nums[j]-nums[i];
                res = max(res,2+solve(i,d,nums));
            }
        }

        return res;
    }
};