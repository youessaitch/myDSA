class Solution {
public:
    int n,m;

    bool check(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int ans = 0;
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int ex, int ey){
        if(!check(i,j) || vis[i][j]==-1) return;

        if(i == ex && j == ey){
            bool ch = true;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(vis[i][j]==0 && grid[i][j]==0){
                        ch = false;
                        break;
                    }
                }
                if(!ch) break;
            }
            if(ch) ans++;
            return;
        }

        vis[i][j]=-1;

        dfs(i+1,j,grid,vis,ex,ey);
        dfs(i-1,j,grid,vis,ex,ey);
        dfs(i,j+1,grid,vis,ex,ey);
        dfs(i,j-1,grid,vis,ex,ey);

        vis[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        vis = grid;
        int sx,sy;
        int ex,ey;
        bool milgya = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    ex = i;
                    ey = j;
                    milgya = true;
                    break;
                }
            }
            if(milgya) break;
        }
        
        milgya = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,vis,ex,ey);
                    milgya = true;
                    break;
                }
            }
            if(milgya) break;
        }
        return ans;

    }
};