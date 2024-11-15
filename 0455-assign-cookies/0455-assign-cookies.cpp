class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        cout<<"n: "<<n<<" m: "<<m<<endl;
        map<int,int> mpp;
        for(auto it: s) mpp[it]++;
        int ans = 0;
        for(int i=0;i<n;i++){
            auto it = mpp.lower_bound(g[i]);
            if(it!=mpp.end()){
                it->second--;
                ans++;
                if(it->second==0) mpp.erase(it);
            }

            if(mpp.size()==0) break;
        }
        return ans;
    }
};