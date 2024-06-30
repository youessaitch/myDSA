class Solution {
public:
    #define ll long long

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end()); //sort 

        for(ll i=0;i<n;i++){
            ll tar = target - nums[i]; //decrease first number from target
            for(ll j=i+1;j<n;j++){
                ll check = tar - nums[j]; //decrease second number from target
                ll l = j+1, r = n-1; // look for other two numbers
                while(l<r){
                    ll sum = nums[l]+nums[r];
                    if(sum == check){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++; //if we get one answer look further for more
                        r--;
                    }
                    else if(sum<check) l++; //simple two pointer
                    else r--;
                }
            }
        }
        // cout<<ans.size()<<endl;
        set<vector<int>> temp; //avoid duplicates
        for(auto it: ans) temp.insert(it);
        ans.clear();
        for(auto it: temp) ans.push_back(it); //answer
        return ans;
    }
};