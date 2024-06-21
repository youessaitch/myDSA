class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;   
        int maxi = 0;  
        int left = 0; 
        int zeroCount = 0; 

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                zeroCount++;
            } else {
                cnt++;
            }

            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                } else {
                    cnt--;
                }
                left++;
            }

            // Update maxi, but since we are asked to remove one element, we consider (i - left)
            maxi = max(maxi, cnt);
        }

        // If the entire array is 1's, we need to remove one element to form the subarray
        if (maxi == n) return maxi - 1;

        return maxi;
    }
};
