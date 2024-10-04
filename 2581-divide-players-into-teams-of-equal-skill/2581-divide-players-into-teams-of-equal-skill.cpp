#define ll long long
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(),skill.end());

        unordered_map<ll,ll> mpp;

        ll ans = 0;
        int i = 0, j = n-1;
        while(i<j){
            ll sum = skill[i]+skill[j];
            mpp[sum]++;

            if(mpp.size()==1){
                ll prod = (ll)skill[i]*(ll)skill[j];
                ans += prod;
            }else{
                if(mpp.size()>1) return -1;
            }

            i++;
            j--;
        }

        return ans;
    }
};