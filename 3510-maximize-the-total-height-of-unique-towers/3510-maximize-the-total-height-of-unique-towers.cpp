#define ll long long
class Solution {
public:
    long long maximumTotalSum(vector<int>& v) {
        int n = v.size();
        sort(v.rbegin(), v.rend());
        ll ans = 0;
        ll prev = v[0];
        ans += v[0];

        for(int i=1;i<n;i++){
            int maxi = v[i];
            if(v[i] >= prev){
                v[i] = prev-1;
            }
            if(v[i]<=0) return -1;
            ans += v[i];
            prev = v[i];
        }

        return ans;
    }
};