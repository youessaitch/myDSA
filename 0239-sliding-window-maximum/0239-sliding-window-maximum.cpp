class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        map<int,int, greater<int>> ms;
        for(int i=0;i<k;i++) ms[nums[i]]++;
        ans.push_back(ms.begin()->first);
        int i=0;
        for(int j=k;j<n;j++){
           ms[nums[i]]--;
           if(ms[nums[i]]==0) ms.erase(nums[i]);
           ms[nums[j]]++;
           i++;
           ans.push_back(ms.begin()->first);
        }
        return ans;
    }
};