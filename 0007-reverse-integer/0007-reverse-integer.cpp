class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        long long num = 0;
        string s = to_string(abs(x));
        string ans = "";
        for(int i=s.size()-1;i>=0;i--){
            ans+=s[i];
        } 
        num = stol(ans);
        if (num > INT_MAX) return 0;
        if(x<0) return -num;
        else return num;
    }
};