class Solution {
public:
    int n;
    bool dfs(int node, int adj[][100], int color[], int col, int vis[]){
        vis[node] = 1;
        color[node] = col;

        for(int it=0;it<n;it++){
            if(adj[node][it] == 1){
                if(color[it] == col) return false;
                if(!vis[it]){
                    if(dfs(it,adj,color,!col,vis)==false) return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        int adj[100][100] = {0};
        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                adj[i][it] = 1;
                adj[it][i] = 1;
            }
        }

        int color[100];
        std::fill(color, color + n, -1); 
        int col = 1;
        int vis[100] = {0};

        for(int i=0;i<n;i++){
            if(!vis[i] && dfs(i,adj,color,col,vis)==false) return false;
        }
        
        return true;
    }
};