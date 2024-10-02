class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low, vector<int> &vis, vector<vector<int>> &bridges){
        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer ++;

        for(auto it: adj[node]){
            if(it == parent) continue; // we dont want to update low with parent

            if(!vis[it]){ //if not visited
                dfs(it, node, adj, tin, low, vis, bridges);
                low[node] = min(low[node], low[it]);

                if(low[it] > tin[node]){ //if after dfs low[child] > tin [parent] then bridge found {node -- it ==== parent -- child}
                    bridges.push_back({node, it});
                }
            }else{ //if visited then only can update low
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n,0);
        vector<int> tin(n,0);
        vector<int> low(n,0);

        vector<vector<int>> bridges;

        dfs(0, -1, adj, tin, low, vis, bridges);

        return bridges;
    }
};