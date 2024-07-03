class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                t += tolower(s[i]);
            }
        }
        string p = t;
        reverse(p.begin(),p.end());
        return p==t;
    }
};