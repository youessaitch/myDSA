class Solution {
public:
    int n;
    int countSeniors(vector<string>& details) {
        n = details.size();
        string age = "";
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            age+=details[i][11];
            age+=details[i][12];
            mpp[stoi(age)]++;
            age="";
        }
        int ans = 0;
        for(auto it: mpp){
            if(it.first>60) ans+=it.second;
        }
        return ans;
    }
};