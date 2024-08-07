class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,vector<int>> mpp;
        int i=0;
        for(auto it: arr){
            mpp[it].push_back(i);
            i++;
        }
        vector<pair<int,string>> v;
        for (auto it = mpp.begin(); it != mpp.end(); it++) {
            if(it->second.size()==1){
                v.push_back({it->second[0],it->first});
            }
        }

        auto lambda = [](const pair<int,string> &A, const pair<int,string> &B){
            return A.first < B.first;
        };
        sort(v.begin(),v.end(),lambda);

        string ans;
        if(v.size()<k) return "";

        return v[k-1].second;
    }
};