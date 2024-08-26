class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for(int i=0;i<n/2;i++){
            for(int j=0;j<m/2;j++){
                int x = grid[i][j];
                x += grid[i][m-j-1];
                x += grid[n-i-1][j];
                x += grid[n-i-1][m-j-1];
                int ones = x;
                int zeros = 4-x;
                ans += min(ones,zeros);
            }
        }

        int cnt = 0; //flips
        int c = 0; //pairs of ones

        //odd row
        if(m%2==1){
            for(int i=0;i<n/2;i++){
                if(grid[i][m/2] != grid[n-i-1][m/2]){
                    ans++;
                    cnt++;
                }

                if((grid[i][m/2] == grid[n-i-1][m/2]) && grid[i][m/2]==1){
                    c++;
                }
            }
        }

        //col odd
        if(n%2==1){
            for(int i=0;i<m/2;i++){
                if(grid[n/2][i] != grid[n/2][m-i-1]){
                    ans++;
                    cnt++;
                }

                if((grid[n/2][i] == grid[n/2][m-i-1]) && grid[n/2][i]==1){
                    c++;
                }
            }
        }
        if(cnt==0 && c%2==1) ans+=2;
        if((n%2==1) && (m%2==1) && (grid[n/2][m/2]==1)) ans++;
        // if()
        return ans;
    }
};