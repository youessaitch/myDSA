class Solution {
public:
    int n;
    int maxSubArray(vector<int>& nums) {
        n = nums.size();
        int maxSum = -1e5;
        int currSum = 0;
        for(int i=0;i<n;i++){
            if(currSum < 0) currSum = 0;

            currSum += nums[i];

            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};