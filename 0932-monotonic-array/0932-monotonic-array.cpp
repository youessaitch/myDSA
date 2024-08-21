class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool ch1 = true;
        bool ch2 = true;
        int n = nums.size();

        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) ch1 = false;

            if(nums[i]<nums[i+1]) ch2 = false;
        }

        if(ch1 || ch2) return true;

        return false;
    }
};