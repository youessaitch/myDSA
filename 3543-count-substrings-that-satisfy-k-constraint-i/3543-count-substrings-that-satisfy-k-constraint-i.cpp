class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int i=0,j=0;
        int cnt0 = 0;
        int cnt1 = 0;
        int ans = 0;
        while(j<n){
            // if(cnt0<=k){
                if(s[j] == '0') cnt0++;
            // }

            // if(cnt1<=k){
                if(s[j]=='1') cnt1++;
            // }
            
            while(cnt0>k && cnt1>k){
                if(s[i]=='0') cnt0--;
                else cnt1--;
                i++;
            }

            ans += j-i+1;
            j++;
        }
        return ans;
    }
};