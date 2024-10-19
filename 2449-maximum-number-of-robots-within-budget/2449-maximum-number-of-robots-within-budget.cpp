#define ll long long

class Solution {
public:
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long b) {
        int n = ct.size();

        int i=0,j=0;

        multimap<int,int> mpp;

        vector<ll> pref(n);
        pref[0] = rc[0];

        for(int i=1;i<n;i++) pref[i] = pref[i-1] + rc[i];
        int ans = 0;

        while(j<n){
            mpp.insert({ct[j],1});

            ll temp = (j-i+1)*(pref[j] - (i>0 ? pref[i-1]:0));

            while(i<=j && (mpp.rbegin()->first + temp > b)){
                auto it = mpp.find(ct[i]);
                if(mpp.find(ct[i]) != mpp.end()) mpp.erase(it);
                i++;

                temp = (j-i+1)*(pref[j] - (i>0 ? pref[i-1]:0));
            }

            ans = max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};