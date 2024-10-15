#define ll long long
class Solution {
public:
    int n;

    long long minimumSteps(string s) {
        n = s.size();
        ll ans = 0;

        ll zeroPos=-1;

        for(int i=n-1;i>=0;i--){
            if(s[i] == '0'){
                zeroPos = i;
                break;
            }
        }

        if(zeroPos == -1) return 0;

        for(int i = zeroPos;i>=0;i--){
            if(s[i] == '1'){
                ans += (zeroPos - i);
                zeroPos--;
            }
        }

        return ans;
    }
};