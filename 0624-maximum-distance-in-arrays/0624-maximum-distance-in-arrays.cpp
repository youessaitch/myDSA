class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int idx = -1, idx1=-1;
        for(int i=0;i<n;i++){
            int m = arrays[i].size();
            if(arrays[i][0] < mini){
                mini = arrays[i][0];
                idx = i;
            }
            if(arrays[i][m-1] > maxi){
                maxi = arrays[i][m-1];
                idx1=i;
            }
        }
        // if maxi and mini are not from same array just return the diff as ans
        if(idx!=idx1)
            return abs(maxi-mini);

        //else, second maxi and second mini
        int s_maxi=INT_MIN, s_mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(i==idx) continue;
            int m = arrays[i].size();
            s_maxi = max(s_maxi,arrays[i][m-1]);
            s_mini = min(s_mini,arrays[i][0]);
        }

        // ans = max of diff between maxi and mini
        return max(abs(maxi-s_mini),abs(s_maxi-mini));
    }
};