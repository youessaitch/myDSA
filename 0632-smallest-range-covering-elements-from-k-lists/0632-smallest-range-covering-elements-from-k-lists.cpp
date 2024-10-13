class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        
        vector<pair<int,int>> v;

        for(int i=0;i<k;i++){
            for(int j=0;j<nums[i].size();j++){
                v.push_back({nums[i][j], i});
            }
        }

        sort(v.begin(),v.end());

        int i=0,j=0;
        int mini = INT_MAX;
        int start = INT_MIN;
        int end = INT_MAX;
        unordered_map<int,int> mpp;

        while(j<v.size()){
            mpp[v[j].second]++;
            j++;

            while (mpp.size() == k) {
                if (v[j - 1].first - v[i].first < mini) {
                    mini = v[j - 1].first - v[i].first;
                    start = v[i].first;
                    end = v[j - 1].first;
                }

                // Shrink the window by moving `i` (left pointer)
                mpp[v[i].second]--;
                if (mpp[v[i].second] == 0) {
                    mpp.erase(v[i].second);
                }
                i++;
            }
        }

        for(auto &it: v){
            cout<<it.first<<" "<<it.second<<endl;

        }

        return {start,end};
    }
};