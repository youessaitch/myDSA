class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        vector<int> ones;
        string s1 = ""; //remove consecutive 0's
        s1+=s[0];

        for(int i=1;i<n;i++){
            if(s[i]=='1') s1+=s[i];
            else if(s[i]=='0'){
                if( s[i] == s[i-1]) continue;
                s1+=s[i];
            }
        }

        cout<<s1<<endl;
        
        int ans = 0;
        int cnt = 0; //cnt for 1's
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='1') cnt++;
            else{
                ans += cnt;
            }
            cout<<cnt<<" ";
        }

        return ans;
    }
};