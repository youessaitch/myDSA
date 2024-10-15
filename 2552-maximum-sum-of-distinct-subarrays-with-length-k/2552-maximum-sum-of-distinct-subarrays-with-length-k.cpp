#define ll long long 

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;

        vector<ll> pref(n,0);
        pref[0] = nums[0];
        for(int k=1;k<n;k++){
            pref[k] = pref[k-1] + nums[k];
        }

        unordered_map<ll,ll> mpp;
        while(j<k){
            mpp[nums[j]]++;
            j++;
        }
        ll ans = 0;

        if(mpp.size()==k){
            ans = max(ans,pref[j-1]);
        }
        mpp[nums[i]]--;
        if(mpp[nums[i]]==0) mpp.erase(nums[i]);
        i++;

        while(j<n){
            mpp[nums[j]]++;

            if(mpp.size()==k){
                ans = max(ans,pref[j]-pref[i-1]);
            }

            mpp[nums[i]]--;
            if(mpp[nums[i]]==0) mpp.erase(nums[i]);

            j++;
            i++;
        }

        return ans;
    }
};