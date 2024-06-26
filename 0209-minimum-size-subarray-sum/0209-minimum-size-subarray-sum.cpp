class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int cnt =INT_MAX;
        int i=0,j=0;
        int sum =0;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                cnt = min(cnt,j-i+1);
                sum-=nums[i];
                i++;
            }
            // if(sum>=target){
            //     cnt = min(cnt,j-i+1);
            // }
            j++;
        }
        if(cnt==INT_MAX) return 0;
        return cnt;
    }
};