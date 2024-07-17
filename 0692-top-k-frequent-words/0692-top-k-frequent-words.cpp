class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        map<string,int> mpp;
        for(auto it: words){
            mpp[it]++;
        }
        vector<pair<int,string>> v;
        for(auto it: mpp){
            v.push_back({it.second,it.first});
        }
        auto lambda = [](const pair<int, string>& A, const pair<int, string>& B) {
            if (A.first != B.first) 
                return A.first > B.first;
            else 
                return A.second < B.second;
        };

        sort(v.begin(),v.end(),lambda);
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};