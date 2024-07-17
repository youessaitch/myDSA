class Solution {
public:
    int n;
    int minEle(vector<int> &nums){
        int l=0, r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]) return mid;

            if(nums[mid]<=nums[r]) r = mid-1;
            else if(nums[mid]>=nums[l]) l=mid+1;
        }
        return -1;
    }

    int findMin(vector<int>& nums) {
        n = nums.size();
        int minIdx = minEle(nums);
        return min(nums[0],nums[minIdx]);
    }
};