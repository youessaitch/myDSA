class Solution {
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }

    // if(check(i+1,j,n,m) && !vis[i+1][j]) 

    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<int>> &vis){

        if(!check(i,j,n,m) || vis[i][j] || grid[i][j]=='0') return;

        vis[i][j]=1;

        dfs(i+1,j,n,m,grid,vis);
        dfs(i-1,j,n,m,grid,vis);
        dfs(i,j+1,n,m,grid,vis);
        dfs(i,j-1,n,m,grid,vis);
    }   

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,n,m,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};