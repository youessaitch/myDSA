class Solution {
public:
    int n;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        n = points.size();
        vector<vector<int>> ans;
        vector<pair<double,vector<int>>> v;
        for(auto it: points){
            int x = it[0];
            int y = it[1];
            double dis = (double)sqrt((double)pow(x,2)+(double)pow(y,2));
            v.push_back({dis,{x,y}});
        }
        sort(v.begin(),v.end());
        for(auto it: v){
            ans.push_back(it.second);
            k--;
            if(k==0) break;
        }
        return ans;
    }
};