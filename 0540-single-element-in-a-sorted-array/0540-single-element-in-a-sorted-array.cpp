class Solution {
public:
    int n;
    int singleNonDuplicate(vector<int>& nums) {
        n = nums.size();
        if(n==1) return nums[0];
        int lo = 0, hi = n-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if((mid==0 && mid+1<n && nums[mid]!=nums[mid+1]) || (mid==n-1 && mid-1>=0 && nums[mid]!=nums[mid-1]) || (mid-1>=0 && mid+1<n && nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])) return nums[mid];
     
            if((mid>0) && (nums[mid-1] == nums[mid])){
                if((mid-1)%2==0) lo = mid+1;
                else hi = mid-1;
            }else if((mid+1<n) && nums[mid] == nums[mid+1]){
                if((mid)%2==0) lo = mid+1;
                else hi = mid-1;
            }
        }
        return -1;
    }
};