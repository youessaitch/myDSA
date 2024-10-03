#define ll long long
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        ll n = word1.size();
        ll m = word2.size();

        vector<ll> v1(26,0);
        vector<ll> v2(26,0);
        
        for(auto it: word2) v2[it-'a']++;

        ll i=0,j=0;
        ll ans = 0;
        bool ch = false;

        while(j<n){
            if(!ch) v1[word1[j]-'a']++;

            ch = true;
            for(int k=0;k<26;k++){
                if (v1[k] < v2[k]){
                    ch = false;
                    break;
                }
            }

            if(ch){
                ll len = n-j;
                ans += len;
                if(i<n){
                    v1[word1[i]-'a']--;
                    i++;
                }
            }else j++;
        }

        return ans;
    }
};