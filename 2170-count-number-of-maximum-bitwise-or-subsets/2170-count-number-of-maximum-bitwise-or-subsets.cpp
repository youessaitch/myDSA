class Solution {
public:
    int n;
    unordered_map<int,int> mpp;

    void solve(int i, vector<int> &nums, int orr, int maxi){
        if(i>=n){
            if(orr == maxi) mpp[orr]++;
            return;
        }

        solve(i+1, nums, orr | nums[i], maxi);
        solve(i+1,nums, orr, maxi);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        int orr = 0;
    
        int ans = 0;
        int temp = -1e9;
        int maxi = 0;

        for(auto it: nums){
            maxi = maxi | it;
        }

        solve(0,nums,orr, maxi);
        
        // for(auto it: mpp){
        //     if(it.first > temp) ans = it.second;
        // }

        return mpp.begin()->second;
        // return ans;
    }
};