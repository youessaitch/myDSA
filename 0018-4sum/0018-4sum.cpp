class Solution {
public:
#define ll long long
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(ll i=0;i<n;i++){
            ll tar = target - nums[i];
            for(ll j=i+1;j<n;j++){
                ll check = tar - nums[j];
                ll l = j+1, r = n-1;
                while(l<r){
                    ll sum = nums[l]+nums[r];
                    if(sum == check){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                    }
                    else if(sum<check) l++;
                    else r--;
                }
            }
        }
        cout<<ans.size()<<endl;
        set<vector<int>> temp;
        for(auto it: ans) temp.insert(it);
        ans.clear();
        for(auto it: temp) ans.push_back(it);
        return ans;
    }
};