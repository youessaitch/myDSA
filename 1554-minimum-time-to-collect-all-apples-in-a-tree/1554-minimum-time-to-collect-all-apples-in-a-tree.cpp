class Solution {
public:
    
    int dfs(int node, int myCost, vector<vector<int>> &adj, vector<int> &vis, vector<bool> &hasApple){
        vis[node] = 1;  // Mark this node as visited

        int childCost = 0;
        // Visit all children (adjacent nodes)
        for(auto it: adj[node]){
            if (!vis[it]) {
                childCost += dfs(it, 2, adj, vis, hasApple);
            }
        }

        // If no child had apples and this node doesn't have an apple, return 0 (no cost for this path)
        if(childCost == 0 && !hasApple[node]) return 0;

        // Return the cost accumulated for this subtree
        return myCost + childCost;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // Build the adjacency list for the tree
        vector<vector<int>> adj(n);
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n, 0);  // Visited array

        // Start DFS from node 0 with an initial cost of 0
        int ans = dfs(0, 0, adj, vis, hasApple);
        return ans;
    }
};
