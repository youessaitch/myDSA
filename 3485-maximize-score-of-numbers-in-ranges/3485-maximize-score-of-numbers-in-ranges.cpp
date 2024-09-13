#define ll long long
class Solution {
public:
    int n;
    int check(vector<int>&v,ll mid, int d){
        ll curr = v[0];
        for(int i=1;i<n;i++){
            if(curr+mid < v[i]){
                curr = v[i];
            }else if(curr+mid <= (ll)(v[i]+d)){
                curr = curr+mid;
            }else return false;
        }
        return true;
    }

    int maxPossibleScore(vector<int>& v, int d) {
        n = v.size();
        sort(v.begin(),v.end());
        ll l=0, r=v[n-1]-v[0]+d;
    
        ll ans = 0;

        while(l<=r){
            ll mid = l+(r-l)/2;
            if(check(v,mid,d)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }

        return ans;

    }
};