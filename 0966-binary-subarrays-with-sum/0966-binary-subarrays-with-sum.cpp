class Solution {
public:
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mpp;
        int ans=0,sum=0;
        mpp[0]=1;
        for(auto it: nums){
            sum+=it;
            ans += mpp[sum-goal];
            mpp[sum]++;
        }
        return ans;
    }

};