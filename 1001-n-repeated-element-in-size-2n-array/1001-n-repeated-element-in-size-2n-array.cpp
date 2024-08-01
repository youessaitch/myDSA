class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(auto it: nums) mpp[it]++;
        for(auto it: mpp){
            if(it.second>1) return it.first;
        }
        return -1;
    }
};