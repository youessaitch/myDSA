class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int> mpp;
        for(auto it: nums2) mpp[it]++;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mpp.find(nums1[i])!=mpp.end()){
                ans.push_back(nums1[i]);
                mpp[nums1[i]]--;
                if(mpp[nums1[i]]==0) mpp.erase(nums1[i]);
            }
        }
        return ans;
    }
};