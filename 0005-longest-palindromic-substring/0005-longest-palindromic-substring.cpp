class Solution {
public:
    int n;
    // vector<vector<int>> dp;

    // bool solve(int i, int j, string &s){
    //     if(i>=j) return true;

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     if(s[i]==s[j]){
    //         return dp[i][j] = solve(i+1,j-1,s);
    //     }

    //     return dp[i][j] = false;
    // }

    string longestPalindrome(string s) {
        n = s.size();

        string ans = ""; //ans
        int maxi = 0; //size
        // dp.resize(n,vector<int>(n,-1));
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(solve(i,j,s)){
        //             if((j-i+1) > maxi){
        //                 maxi = (j-i+1);
        //                 ans = s.substr(i,maxi);
        //             }
        //         }
        //     }
        // }

        for(int i=0;i<n;i++){
            int l=i,r=i;

            while(l>=0 && r<=n && s[l]==s[r]){
                if(r-l+1 > maxi){
                    maxi = r-l+1;
                    ans = s.substr(l,maxi);
                }
                l--;
                r++;
            }

            l=i,r=i+1;
            while(l>=0 && r<=n && s[l]==s[r]){
                if(r-l+1 > maxi){
                    maxi = r-l+1;
                    ans = s.substr(l,maxi);
                }
                l--;
                r++;
            }
        }

        return ans;
    }
};