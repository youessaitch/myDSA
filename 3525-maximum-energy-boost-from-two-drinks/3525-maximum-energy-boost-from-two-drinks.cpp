#define ll long long
class Solution {
public:
    int n;
    vector<vector<ll>>dp;

    ll solve(int i, int p, vector<int> &energyDrinkA, vector<int> &energyDrinkB){
        if(i>=n) return 0;

        if(dp[i][p]!=-1) return dp[i][p];

        ll take = INT_MIN;
        if(p==0){
            take = (ll)energyDrinkA[i] + solve(i+1,0,energyDrinkA,energyDrinkB);
        }else{
            take = (ll)energyDrinkB[i] + solve(i+1,1,energyDrinkA,energyDrinkB);
        }

        ll notTake = solve(i+1,1-p,energyDrinkA,energyDrinkB);

        return dp[i][p] = (ll)max(take,notTake);
    }

    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        n = energyDrinkA.size();
        dp.resize(n+1,vector<ll>(2,-1)); //p=0 :A or p=0 :B

        return max(solve(0,0,energyDrinkA,energyDrinkB),solve(0,1,energyDrinkA,energyDrinkB));
    }
};