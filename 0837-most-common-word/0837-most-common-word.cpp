class Solution {
public:
    string mostCommonWord(string p, vector<string>& b) {
        unordered_map<string,int> mp1;
        int n = p.size();

        string s = "";
        for(int i=0;i<n;i++){
            if(isalpha(p[i])){
                s+=tolower(p[i]);
            }else{
                if (!s.empty()) {
                    mp1[s]++;
                    s = "";
                }
            }
        }

        if (!s.empty()) {
            mp1[s]++;
        }

        unordered_map<string,int> mp2;
        int m = b.size();
        for(auto it: b) mp2[it]++;

        string ans = "";
        vector<pair<int,string>> v;
        for(auto it: mp1) v.push_back({it.second,it.first});

        sort(v.begin(), v.end(), greater<pair<int, string>>());

        for(int i=0;i<v.size();i++){
            if(mp2.find(v[i].second)==mp2.end()){
                return v[i].second;
            }
        }

        return "";
    }
};