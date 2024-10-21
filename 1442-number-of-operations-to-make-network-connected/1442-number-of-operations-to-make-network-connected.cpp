class DSU{
    vector<int> rank, par;
public:

    DSU(int n){
        rank.resize(n+1,0);
        par.resize(n+1);

        for(int i=0;i<=n;i++) par[i] = i;
    }

    int find(int node){
        if(par[node] == node) return node;

        return par[node] = find(par[node]);
    }

    void unionByRank(int u, int v){
        int root_u = find(u);
        int root_v = find(v);

        if(root_u == root_v) return;

        if(rank[root_u] < rank[root_v]){
            par[root_u] = root_v;
        }else if(rank[root_u] > rank[root_v]){
            par[root_v] = root_u;
        }else{
            par[root_v] = root_u;
            rank[root_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();

        if(m<n-1) return -1;

        DSU ds(n);

        int cnt = m;
        int t = 0;
        for(auto &it: connections){
            int u = it[0];
            int v = it[1];

            // if(ds.find(u) != ds.find(v)){
            //     ds.unionByRank(u,v);
            //     cnt--;
            //     t++;
            // }
            ds.unionByRank(u,v);
        }

        int components = 0;
        for(int i=0;i<n;i++){
            if(ds.find(i)==i){
                components++;
            }
        }

        return components-1;
    }
};