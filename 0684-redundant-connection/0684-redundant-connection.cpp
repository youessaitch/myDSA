class DSU{
    public:
    vector<int> rank, parent;

    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0;i<=n;i++) parent[i] = i;
    }

    int find(int node){
        if(parent[node] == node) return node;

        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u, int v){
        int root_u = find(u);      
        int root_v = find(v);      

        if(root_u == root_v) return;

        if(rank[root_u] > rank[root_v]) parent[root_v] = root_u;
        else if(rank[root_u] < rank[root_v]) parent[root_u] = root_v;
        else{
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU ds(n);

        vector<vector<int>> ans;

        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            if(ds.find(u) != ds.find(v)){
                ds.unionByRank(u,v);
            }else{
                ans.push_back({u,v});
            }
        }

        return ans.back();
    }
};