class Solution {
public:
    int n,m;
    bool check(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    vector<vector<int>> vis;

    void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, bool &ch){
        if(!check(i,j) || vis[i][j] || grid2[i][j]==0){
            return;
        }

        if(grid2[i][j]==1 && grid1[i][j]==0){
            ch = false;
        }

        vis[i][j]=1;

        dfs(i+1,j,grid1,grid2,ch);
        dfs(i-1,j,grid1,grid2,ch);
        dfs(i,j+1,grid1,grid2,ch);
        dfs(i,j-1,grid1,grid2,ch);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        vis.resize(n,vector<int>(m,0));
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && vis[i][j]==0){
                    bool ch = true;
                    dfs(i,j,grid1,grid2,ch);
                    if(ch) ans++;
                }
            }
        }

        return ans;
    }
};