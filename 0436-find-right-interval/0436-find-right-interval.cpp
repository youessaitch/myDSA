class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            v.push_back({intervals[i][0],intervals[i][1],i,-1});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            // if(v[i+1][0]>=v[i][1]){
            //     v[i][3]=(v[i+1][2]);
            // }
            int lo = i, hi = n-1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(v[mid][0]>=v[i][1]){
                    v[i][3] = v[mid][2];
                    hi=mid-1;
                }else lo= mid+1;
            }
        }
        
        auto lambda = [](const vector<int>&A, const vector<int>&B){
            return A[2]<B[2];
        };

        sort(v.begin(),v.end(),lambda);
        for(auto it: v){
            ans.push_back(it[3]);
        }
        return ans;
    }
};