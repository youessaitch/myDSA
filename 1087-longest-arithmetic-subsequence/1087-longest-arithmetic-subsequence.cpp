//*****Approach 1: Recursion + Memoization*****
// class Solution {
// public:

//     int n;
//     int dp[1001][1003]; //index, difference
//     //NOTE: diff can be 0<=diff<=500, but it can be negative too and we cant give negative indices to the dp so lets add a constant here say 502 => 501+502 = 1003
//     int solve(int i, int d, vector<int> &nums){
//         if(i < 0 ) return 0;

//         if(dp[i][d + 501] != -1) return dp[i][d + 501]; //add constant here too to avoid negative indices, answer wont change

//         int ans = 0;

//         for(int k=i-1; k>=0; k--){
//             if(nums[i]-nums[k] == d){
//                 ans = max(ans,1+solve(k,d,nums));
//             }
//         }
//         return dp[i][d + 501] = ans;
//     }

//     int longestArithSeqLength(vector<int>& nums) {
//         int n = nums.size();
//         int res = 0;

//         memset(dp,-1,sizeof(dp));

//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 int d = nums[j]-nums[i];
//                 res = max(res,2+solve(i,d,nums));
//             }
//         }

//         return res;
//     }
// };

//******Approach 2: LIS*******
//https://www.youtube.com/watch?v=S3ocpdBL-7Y&t=58s
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        
        if(n <= 2)
            return n;
        
        vector<vector<int>> dp(n, vector<int>(1001,0));
        //dp[i][j] = Max AP length till ith index (0 to i) having common difference j

        int result = 0;
        
        for (int i = 1; i<n; i++) {
            
            for (int j=0; j<i; j++) {
                
                int diff    = nums[i] - nums[j] + 500; //to avoid negative diff
                
                dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;
                
                result      = max(result, dp[i][diff]);
            }
        }

        return result;
    }
};