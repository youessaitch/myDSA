class Solution {
public:
    void dfs(int node, int par, vector<vector<pair<int,int>>> &adj, int dis, int signalSpeed, int &cnt){
        if(dis%signalSpeed == 0) cnt++;
        for(auto it: adj[node]){
            int child = it.first;
            int weight = it.second;
            // if(dis%signalSpeed == 0) cnt++;
            if(child != par){
                dfs(child,node,adj,dis+weight,signalSpeed,cnt);
            }
        }
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size()+1;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            vector<int> v;
            int sum = 0;
            for(auto it: adj[i]){
                int node = it.first;
                int dis = it.second;
                int cnt = 0;
                dfs(node,i,adj,dis,signalSpeed,cnt);
                v.push_back(cnt);
                sum += cnt;
            }
            int pairs = 0;
            for(auto it: v){
                pairs += (sum-it)*it;
            }
            res[i] = pairs/2;
        }
        return res;
    }
    
};