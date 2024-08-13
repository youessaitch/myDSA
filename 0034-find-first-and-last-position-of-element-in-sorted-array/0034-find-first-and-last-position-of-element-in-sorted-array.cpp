class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int a=-1;
        int b=-1;
        int lo = 0, hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]==target){
                a = mid;
                hi = mid-1;
            }else if(nums[mid]<target){
                lo = mid+1;
            }else {
                hi = mid-1;
            }
        }

        lo = 0, hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]==target){
                b = mid;
                lo = mid+1;
            }else if(nums[mid]<target){
                lo = mid+1;
            }else {
                hi = mid-1;
            }
        }

        return {a,b};
    }
};