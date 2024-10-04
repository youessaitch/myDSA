class Solution {
public:
    bool bfs(int i, vector<vector<int>> &adj, vector<int> &colors, int currColor){
        queue<int> q;
        q.push(i);
        colors[i] = currColor;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                if(colors[it] == colors[node]) return false;

                if(colors[it] == -1){
                    colors[it] = !colors[node];
                    q.push(it);
                }
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
                if(bfs(i,adj,colors,1) == false) return false;
            }
        }

        return true;
    }
};