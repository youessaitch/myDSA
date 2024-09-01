class Solution {
public:
    vector<string> ans;
    void solve(int n, string t, int open, int close){
        if(t.size()==2*n){
            ans.push_back(t);
            return;
        }

        if(open<n){
            solve(n,t+'(',open+1,close);
        }

        if(close<open){
            solve(n,t+')',open,close+1);
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        string t="";
        solve(n,t,0,0);
        return ans;
    }
};