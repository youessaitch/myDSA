#define ll long long
class Solution {
public:
    int n;

    long long minimumSteps(string s) {
        n = s.size();
        ll ans = 0;
        
        ll zero = 0;

        for(int i=n-1;i>=0;i--){
            if(s[i] == '0') zero++;
            else ans += zero;
        }

        return ans;
    }
};