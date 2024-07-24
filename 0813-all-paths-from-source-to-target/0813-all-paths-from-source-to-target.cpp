class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<int> vis;
    vector<int> temp;

    void dfs(int node, vector<vector<int>> &adj){
        vis[node]=1;
        temp.push_back(node);
        if(node == n-1){
            ans.push_back(temp);
            return;
        }
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj);
            }
            vis[it]=0;
            temp.pop_back();
        }
        
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vis.resize(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(auto it: graph[i])
                adj[i].push_back(it);
        }
        dfs(0,adj);
        return ans;
    }
};