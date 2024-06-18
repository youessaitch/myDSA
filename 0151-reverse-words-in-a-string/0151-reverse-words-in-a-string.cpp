class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> v;
        int i=0;
        while(s[i]==' '){
            i++;
        }
        string temp="";
        while(i<n){
            if(s[i]!=' '){
                temp+=s[i];
                i++;
            }else{
                v.push_back(temp);
                temp="";
                while(s[i]==' '){
                    i++;
                }
            }
        }
        if(s[n-1]!=' ') v.push_back(temp);
        reverse(v.begin(),v.end());

        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        string ans = "";
        ans+=v[0];
        int m = v.size();
        if(v.size()>1){
            ans+=" ";
            for(int i=1;i<m-1;i++){
                ans+=v[i];
                ans+=' ';
            }
            ans+=v[m-1];
        }
        return ans;
    }
};