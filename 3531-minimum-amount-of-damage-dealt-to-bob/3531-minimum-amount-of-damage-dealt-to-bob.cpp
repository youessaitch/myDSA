#define ll long long
class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<pair<ll,ll>> v;
        for(int i=0;i<n;i++){
            v.push_back({damage[i],((health[i]+power-1)/power)});
        }

        // ll maarKhao = accumulate(damage.begin(), damage.end(), 0LL);

        auto lambda = [](const pair<ll,ll>&a, const pair<ll,ll> &b){
            ll d1 = a.first;
            ll d2 = b.first;
            ll time1 = a.second;
            ll time2 = b.second;
            //first kill a then kill b
            ll damage1 = d1*time1 + d2*(time1+time2);
            ll damage2 = d2*time2 + d1*(time1+time2);
            return damage1 < damage2;
        };

        sort(v.begin(),v.end(),lambda);

        for(auto it: v){
            cout<<it.first<<" "<<it.second<<endl;
        }

        ll ans = 0;
        ll cnt = 0;

        for(int i=0;i<n;i++){
            cnt += v[i].second;

            ans += (ll)cnt*v[i].first;
            // maarKhao -= v[i].first;
        }

        return ans;
    }
};