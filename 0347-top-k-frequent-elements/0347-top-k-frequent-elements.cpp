class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto it: nums) mpp[it]++;

        multimap<int,int,greater<int>> mp1;
        for(auto it: mpp){
            mp1.insert({it.second,it.first});
        }

        vector<int> v;
        int cnt=0;
        for(auto it: mp1){
            v.push_back(it.second);
            cnt++;
            if(cnt==k) break;
        }

        return v;
    }
};