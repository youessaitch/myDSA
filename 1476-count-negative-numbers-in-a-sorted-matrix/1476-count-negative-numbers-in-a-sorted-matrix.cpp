class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int lo=0, hi=m-1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(grid[i][mid]<0){
                    hi=mid-1;
                }else lo=mid+1;
            }
            ans+=(m-lo);
        }
        return ans;
    }
};