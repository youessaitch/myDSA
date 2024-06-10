class Solution {
public:
    int solve(vector<int>&nums, int goal){
        int n = nums.size();
        int l = 0,r=0,cnt=0,sum=0;

        while (r < n) {
            sum += nums[r];

            while (l <= r && sum > goal) {
                sum -= nums[l];
                l++;
            }

            cnt += r - l + 1;

            r++;
        }

        return cnt;
    }

    //(No of subarrays where sum <= goal) - (No of subarrays where sum <= goal-1) = (No of subarrays where sum == goal)
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }

};