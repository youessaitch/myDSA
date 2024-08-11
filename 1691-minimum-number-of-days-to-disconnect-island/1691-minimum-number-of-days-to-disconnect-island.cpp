class Solution {
public:
    int n,m;
    bool check(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }

    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis){
        if(!check(i,j) || vis[i][j] || grid[i][j]==0) return;

        vis[i][j] = 1;

        dfs(i+1,j,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i,j-1,grid,vis);
    }

    int islandCnt(vector<vector<int>>& grid){
        vector<vector<int>> vis(n,vector<int>(m,0));
        int islands = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(i,j,grid,vis);
                    islands++;
                }
            }
        }

        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int islands = islandCnt(grid);
        
        if(islands!=1) return 0;

       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(islandCnt(grid)!=1) return 1;
                    grid[i][j]=1;;
                }
            }
        }

        return 2;
    }
};