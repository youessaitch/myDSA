class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());
        int mini = nums[n-1]-nums[0];
        for(int i=0;i<=3;i++){
            mini = min(mini,nums[n-4+i]-nums[i]);
        }
        return mini;
    }
    //0 1 1 4 6 6 6 
    // 0 1 5 10 14 
//     Remove the last 3 elements.
// Remove the first 3 elements.
// Remove the first 1 and last 2 elements.
// Remove the first 2 and last 1 elements.
};