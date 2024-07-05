class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        // Kadane's algorithm to find the maximum subarray sum
        int maxSum = INT_MIN;
        int currMax = 0;
        for(int i = 0; i < n; i++) {
            currMax = max(currMax + nums[i], nums[i]);
            maxSum = max(maxSum, currMax);
        }
        
        // Kadane's algorithm to find the minimum subarray sum
        int minSum = INT_MAX;
        int currMin = 0;
        for(int i = 0; i < n; i++) {
            currMin = min(currMin + nums[i], nums[i]);
            minSum = min(minSum, currMin);
        }
        
        // Calculate the total sum of the array
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // If all elements are negative, maxSum is the result
        if (totalSum == minSum) return maxSum;
        
        // Return the maximum of the non-circular and circular subarray sums
        return max(maxSum, totalSum - minSum);
    }
};
