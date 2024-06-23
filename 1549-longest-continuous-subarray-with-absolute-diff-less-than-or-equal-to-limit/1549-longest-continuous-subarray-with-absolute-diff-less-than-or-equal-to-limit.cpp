class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> ms;
        int l=0,r=0;
        int ans = 0;
        while(r<n){
            ms.insert(nums[r]);
            auto maxi = *ms.rbegin();
            auto mini = *ms.begin();
            while(abs(maxi-mini) > limit){
                ms.erase(ms.find(nums[l]));
                l++;
                maxi = *ms.rbegin();
                mini = *ms.begin();
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};