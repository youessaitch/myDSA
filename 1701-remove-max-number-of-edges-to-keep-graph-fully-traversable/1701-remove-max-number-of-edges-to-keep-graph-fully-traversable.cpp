class DSU {
public:
    vector<int> rank, parent;
    int components; //to keep the cnt of components

    DSU(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        components = n;
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u == root_v)
            return;

        if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else if (rank[root_v] < rank[root_u]) {
            parent[root_v] = root_u;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }

        components--; //union krne pr number of components decrease hoga thats why
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);

        auto lambda = [](vector<int> &v1, vector<int> &v2){
            return v1[0] > v2[0];
        };

        sort(edges.begin(),edges.end(),lambda); //we want to use Type 3 edges first

        int edgeCnt = 0;

        for(auto it: edges){
            int type = it[0];
            int u = it[1];
            int v = it[2];

            if(type == 3){ //both Alice and Bob can travel
                bool edgeAddKro = false;

                //Alice
                if(Alice.find(u)!=Alice.find(v)){
                    Alice.unionByRank(u,v);
                    edgeAddKro = true;
                }

                //Bob
                if(Bob.find(u)!=Bob.find(v)){
                    Bob.unionByRank(u,v);
                    edgeAddKro = true;
                }

                if(edgeAddKro) edgeCnt++;
                
            }else if(type == 2){
                //Bob only
                if(Bob.find(u)!=Bob.find(v)){
                    Bob.unionByRank(u,v);
                    edgeCnt++;
                }
            }else if(type == 1){
                //Alice only
                if(Alice.find(u)!=Alice.find(v)){
                    Alice.unionByRank(u,v);
                    edgeCnt++;
                }
            }
        }

        //Now we must have both Alice and Bob to have only 1 component so that all nodes can be traversed
        if(Alice.components==1 && Bob.components==1){
            return edges.size() - edgeCnt; //edge to be removed
        }

        return -1;

    }
};