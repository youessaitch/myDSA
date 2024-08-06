class Solution {
public:
    int n;
    int minimumPushes(string word) {
        n = word.size();
        unordered_map<char,int> mpp;
        for(auto it: word) mpp[it]++;
        if(mpp.size()<=8) return word.size();
        
        vector<int> v;
        for(auto it: mpp) v.push_back(it.second);
        sort(v.begin(),v.end(),greater<int>());
        int ans = 0;
        int m = v.size();
        int k = mpp.size()/8;
        int rest = mpp.size()%8;
        int start = 0;
        int end = 7;
        for(int i=1;i<=k;i++){
            for(int j=start;j<=end;j++){
                ans += i*v[j];
            }
            start+=8;
            end+=8;
        }
        for(int j = start;j<rest+start;j++){
            ans += (k+1)*v[j];
        }
        return ans;
        
    }
};