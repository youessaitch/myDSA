class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        // multiset<int> ms;
        map<int,int> ms;
        for(int i=0;i<k;i++) ms[nums[i]]++;
        // auto it = *ms.rbegin();
        // ans.push_back(it);
        ans.push_back(ms.rbegin()->first);
        for(int i=k;i<n;i++){
           ms[nums[i-k]]--;
           if(ms[nums[i-k]]==0) ms.erase(nums[i-k]);
           ms[nums[i]]++;
           ans.push_back(ms.rbegin()->first);
        }
        return ans;
    }
};