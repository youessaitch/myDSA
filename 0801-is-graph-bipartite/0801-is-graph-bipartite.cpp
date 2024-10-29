class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &color, int col, vector<int> &vis){
        vis[node] = 1;
        color[node] = col;

        for(auto &it: adj[node]){
            if(color[it] == col) return false;
            if(!vis[it]){
                if(dfs(it,adj,color,!col,vis)==false) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                adj[i].push_back(it);
                adj[it].push_back(i);
            }
        }

        vector<int> color(n,-1);
        int col = 1;
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i] && dfs(i,adj,color,col,vis)==false) return false;
        }
        
        return true;
    }
};