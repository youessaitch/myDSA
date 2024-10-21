class Solution {
public:
    int n;
    int ans = 0;
    vector<string> c;
    void solve(int i, string &s, string temp,unordered_map<string,int> &mpp){
        if(i>=n){   //arey behencho
            if(mpp.size()>ans){
                ans = mpp.size();
            }
            return;
        }

        for(int j=i;j<n;j++){
            temp += s[j];
            // c.push_back(temp);
            if(mpp.find(temp)==mpp.end()){
                // c.push_back(temp);
                mpp[temp]++;
                // cout<<"$$"<<" ";
                solve(j+1,s,"",mpp);
                mpp.erase(temp);
                // cout<<"$$"<<" ";
                // c.pop_back();
            }
        }
    }

    int maxUniqueSplit(string s) {
        n = s.size();
        string temp = "";
        unordered_map<string,int> mpp;
        solve(0,s,temp,mpp);

        // for(auto it: c) cout<<it<<" ";
        // cout<<endl;

        return ans;
    }
};