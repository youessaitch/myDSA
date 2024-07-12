class Solution {
public:
    vector<string> ans;

    void solve(int i, int prev, int n, string temp){
        if(i>=n){
            ans.push_back(temp);
            return;
        }

        if(prev>=0 && temp[prev] == '0'){
            solve(i+1,i,n,temp+'1');
        }else{
            solve(i+1,i,n,temp+'0');
            solve(i+1,i,n,temp+'1');
        }
    }

    vector<string> validStrings(int n) {
        string temp="";
        solve(0,-1,n,temp);
        return ans;
    }
};