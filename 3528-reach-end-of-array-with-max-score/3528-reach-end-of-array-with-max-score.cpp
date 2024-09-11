#define ll long long
class Solution {
public:
    int n;
    // vector<ll> dp;

    // ll solve(int i, vector<int>&nums){
    //     if(i>=n) return 0;

    //     if(dp[i]!=-1) return dp[i];

    //     ll take = 0;

    //     for(int j=i+1;j<n;j++){
    //         take = max(take,(ll)(j-i)*nums[i] + solve(j,nums));
    //     }

    //     ll notTake = solve(i+1,nums);

    //     return dp[i] = max(take,notTake);
    // }

    long long findMaximumScore(vector<int>& nums) {
        n = nums.size();
        // dp.resize(n,-1);
        // return solve(0,nums);
        vector<ll> nger(n,-1);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            if(!st.empty() && nums[st.top()]>nums[i]) nger[i]=st.top();
            st.push(i);
        }

        for(int i=0;i<n;i++){
            cout<<nger[i]<<" ";
        }
        cout<<endl;

        ll cnt = 0;
        if(nger[0]==-1) return (ll)nums[0]*(n-1-0);

        ll i = 0;

        while(i<n){
            if(nger[i]==-1){
                cnt += (ll)nums[i] * (n - 1 - i);
                break;
            }
            cnt += (ll)nums[i]*(nger[i]-i);
            i = nger[i];
        }
        return cnt;
    }   
};