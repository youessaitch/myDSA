class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = -1;
        int i=0, j=n-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid]==target){
                ans = mid;
                break;
            }else if(nums[mid]<target){
                i=mid+1;
            }else j=mid-1;
        }
        return ans;
    }
};