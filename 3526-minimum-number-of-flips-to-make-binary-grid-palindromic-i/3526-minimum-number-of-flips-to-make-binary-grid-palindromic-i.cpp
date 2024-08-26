class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MAX;

        //row
        int cntr = 0;
        for(int i=0;i<n;i++){
            int j=0, k=m-1;
            while(j<k){
                if(grid[i][j]!=grid[i][k]) cntr++;
                j++;
                k--;
            }
        }
        ans = min(ans,cntr);

        //col
        int cntc = 0;
        for(int j=0;j<m;j++){
            int i=0, k=n-1;
            while(i<k){
                if(grid[i][j]!=grid[k][j]) cntc++;
                i++;
                k--;
            }
        }
        ans = min(ans,cntc);

        return ans;
    }
};