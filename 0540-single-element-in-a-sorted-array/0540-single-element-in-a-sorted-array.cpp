class Solution {
public:
    //Note: before the required element to be found, the index of elements at the first occurrence will be even and after that required element, the index of first occurences will be odd
    //e.g. 1 1 2 3 3 4 4 8 8
    //idx  0 1 2 3 4 5 6 7 8
    //2 is the required element
    //before 2 first occurences exist at index: 0 (even)
    //after 2 first occurences exist at index: 3,5,7(odd)
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