class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int target = 0 - nums[i];
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[j]+nums[k] == target){ 
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k] < target) j++;
                else k--;
            }
        }
        vector<vector<int>> ans;
        for(auto it: st){
            ans.push_back(it);
        }

        return ans;
    }
};