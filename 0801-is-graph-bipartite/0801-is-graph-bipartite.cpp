class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &colors, int currColor){
        colors[node] = currColor;

        for(auto it: adj[node]){
            if(colors[it]==currColor) return false;

            if(colors[it]==-1){
                if(dfs(it,adj,colors,1-currColor) == false) return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(auto it: graph[i])
                adj[i].push_back(it);
        }

        vector<int> colors(n,-1);

        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                if(dfs(i,adj,colors,1) == false) return false;
            }
        }

        return true;
    }
};