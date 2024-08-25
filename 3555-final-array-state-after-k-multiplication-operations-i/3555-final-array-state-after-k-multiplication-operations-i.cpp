class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        while(k--){
            int idx = -1;
            int mini = INT_MAX;
            for(int i=0;i<n;i++){
                if(nums[i]<mini){
                    mini = nums[i];
                    idx = i;
                }
            }
            nums[idx] = nums[idx]*multiplier;
        }
        return nums;
    }
};