class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int j=0,i=0;

        int prod = 1;
        int ans = 0;

        while(j<n){
            prod = prod*nums[j];

            while(i<=j && prod>=k){
                prod = prod/nums[i];
                i++;
            }

            ans += (j-i+1);

            j++;
        }

        return ans;
    }
};