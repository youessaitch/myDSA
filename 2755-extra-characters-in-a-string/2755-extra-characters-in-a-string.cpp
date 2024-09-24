class Solution {
public:
    int n;
    unordered_map<string,int> mpp;
    vector<int> dp;

    int solve(int i, string &s){
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        int extra = INT_MAX;
        string t = "";

        for(int j = i; j < n; j++){
            t += s[j];
            if(mpp.find(t)!=mpp.end()){
                int temp = solve(j+1,s);
                extra = min(extra,temp); //spliiting the string
            }
        }

        extra = min(extra,1+solve(i+1,s)); //skipping a character, thats why +1
        
        return dp[i] = extra;
    }

    int minExtraChar(string s, vector<string>& dict) {
        n = s.size();

        for(auto it: dict) mpp[it]++;

        dp.resize(n,-1);

        return solve(0,s);

    }
};