class Solution {
public:
    int n, m;
    bool check(int i, int j){
        return i>=0 && j>=0 && i<n*3 && j<m*3;
    }

    void dfs(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &vis){
        if(!check(i,j) || vis[i][j] || mat[i][j]==1) return;

        vis[i][j]=1;

        dfs(i+1,j,mat,vis);
        dfs(i,j+1,mat,vis);
        dfs(i-1,j,mat,vis);
        dfs(i,j-1,mat,vis);
    }

    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;

        vector<vector<int>> mat(n*3,vector<int>(m*3,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='/'){
                    mat[i*3][j*3+2]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3]=1;
                }else if(grid[i][j]=='\\'){
                    mat[i*3][j*3]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3+2]=1;
                }
            }
        }

        vector<vector<int>> vis(n*3,vector<int>(m*3,0));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0 && !vis[i][j]){
                    dfs(i,j,mat,vis);
                    ans++;
                }
            }
        }

        return ans;
    }
};