class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> mpp;
        for(auto ch:s) mpp[ch]++;

        int ans = 0;
        int odd= 0;
        int even = 0;
        int odd_even = 0;
        bool oddd=0;
        for(auto it: mpp){
            if(it.second%2==0) even+=it.second;
            else{  
                oddd=1;
                odd=max(odd,it.second);
                odd_even += it.second-1;}
        }
        ans+=even;
        if(oddd){
            ans+=odd;
            ans+=odd_even-(odd-1);
        }
        
        // ans+=odd_even;
        // if(odd_even>=0) ans+=odd_even+1;
        return ans;
    }
};