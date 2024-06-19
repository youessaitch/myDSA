#define ll long long int
class Solution {
public:
    ll solve(int mid, vector<int>&bloomDay, int k){
        ll n = bloomDay.size();
        ll cnt = 0;
        ll bouq=0;
        for(ll i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }else{
                bouq += cnt/k;
                cnt=0;
            }
        }
        bouq+=cnt/k;
        return bouq;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        ll n = bloomDay.size();
        ll lo = 1; //day
        ll hi = (ll)*max_element(bloomDay.begin(),bloomDay.end()); //max day
        ll ans = 1e10;
        while(lo<=hi){
            ll mid = lo+(hi-lo)/2;
            ll cnty = solve(mid,bloomDay,k);
            if(cnty>=m){
                ans = min(ans,mid);
                hi=mid-1;
            }
            else lo = mid+1;

        }
        if(ans == 1e10) return -1;
        return ans;
    }
};