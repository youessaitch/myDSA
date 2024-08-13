class Solution {
public:
    int n;
    // vector<vector<int>> dp;
    set<vector<int>> ans;

    void solve(int i, int target, vector<int>&candidates, vector<int> &ds){
        if(target==0){
            ans.insert(ds);
            return;
        }

        if(i>=n || target<0) return;

        // if(dp[i][target]!=-1) return dp[i][target];

        // int take = 0;
        if(candidates[i]<=target){
            ds.push_back(candidates[i]);
            solve(i+1,target-candidates[i],candidates,ds);
            ds.pop_back();
        }

        while (i + 1 < n && candidates[i] == candidates[i + 1]) {
            i++;
        }

        solve(i+1,target,candidates,ds);
        
        // return dp[i][target] = take + notTake;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        // dp.resize(n,vector<int>(target+1,-1));
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,ds);
        vector<vector<int>> sol;
        for(auto it: ans){
            sol.push_back(it);
        }
        return sol;
    }
};