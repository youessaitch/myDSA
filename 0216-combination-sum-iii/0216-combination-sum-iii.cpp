class Solution {
public:
    void solve(int i, int k, int n, vector<vector<int>> &ans, vector<int> &ds){

        if(k==0){
            if(n==0){
                ans.push_back(ds);
            }
            return;
        }

        if(i>9) return;

        //take
        if(i<=n){
            ds.push_back(i);
            solve(i+1,k-1,n-i,ans,ds);
            ds.pop_back();
        }

        //notTake
        solve(i+1,k,n,ans,ds);
        
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,k,n,ans,ds);
        return ans;
    }
};