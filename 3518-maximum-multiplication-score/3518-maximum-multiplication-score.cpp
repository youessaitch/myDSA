#define ll long long
class Solution {
public:
    ll n,m;
    vector<vector<ll>> dp;

    ll solve(int i, int j, vector<int> &a, vector<int> &b){
        if(i>=n) return 0;

        if(j>=m) return -1e15;

        if(dp[i][j]!=-1) return dp[i][j];
        
        ll take = (ll)a[i]*(ll)b[j] + solve(i+1,j+1,a,b);

        ll notTake = solve(i,j+1,a,b);

        return dp[i][j] = max(take,notTake);
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        n = a.size();
        m = b.size();

        dp.resize(n,vector<ll>(m,-1));

        return solve(0,0,a,b);
    }
};