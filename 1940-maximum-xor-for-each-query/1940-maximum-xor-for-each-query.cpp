class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans(n);
        int xorr = nums[0];
        int maxxorr = pow(2,maximumBit)-1;
        for(int i=1;i<n;i++) xorr^=nums[i];
        for(int i=0;i<n;i++){
            ans[i] = xorr^maxxorr; // x= given^maxxorr
            xorr^=nums[n-1-i]; //remove last element by xoring it to total
        }
        return ans;
    }
};

// given^x = maxxorr
// x = maxxorr^given