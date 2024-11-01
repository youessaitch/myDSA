class Solution {
public:
    map<pair<int,int>,int> mpp;
    void dfs(int node, int parent, vector<vector<int>> &adj, int &cnt, vector<int> &vis){
        vis[node] = 1;

        for(auto &it: adj[node]){
            int par = node;
            int chd = it;

            if(!vis[it]){
                if(mpp.find({par,chd})!=mpp.end()) cnt++;
                dfs(it,node,adj,cnt,vis);
            }   
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        vector<vector<int>> adj(n);
        for(auto &it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            mpp[{it[0],it[1]}]++;
        }

        vector<int> vis(n,0);

        int cnt = 0;
        dfs(0,-1,adj,cnt,vis);
        return cnt;
    }
};