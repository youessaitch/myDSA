	class DisjointSet {
	public:
	    vector<int> rank, parent;
	
	    DisjointSet(int n) {
	        rank.resize(n + 1, 0);
	        parent.resize(n + 1);
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
	        int ulp_u = find(u);
	        int ulp_v = find(v);
	        if (ulp_u == ulp_v) return;
	
	        if (rank[ulp_u] < rank[ulp_v]) {
	            parent[ulp_u] = ulp_v;
	        } else if (rank[ulp_v] < rank[ulp_u]) {
	            parent[ulp_v] = ulp_u;
	        } else {
	            parent[ulp_v] = ulp_u;
	            rank[ulp_u]++;
	        }
	    }
	};


class Solution {
public:
    // void dfs(int node, vector<vector<int>>& stones, vector<int> &vis){
    //     vis[node]=1;
    //     for(int i=0;i<stones.size();i++){
    //         if(!vis[i] && (stones[node][0]==stones[i][0] || stones[node][1]==stones[i][1])){
    //             dfs(i,stones,vis);
    //         }
    //     }
    // }

    int removeStones(vector<vector<int>>& stones) {
        // int n = stones.size();
        // vector<int> vis(n,0);
        // int cnt = 0;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         dfs(i,stones,vis);
        //         cnt++;
        //     }
        // }

        // return n - cnt;


        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        for(auto it: stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }

        //we are making the ds 1D by taking rows as nodes then taking col values ie row = {0 1 2 3 4}, col={0,1,2,3}; then we will take as {0,1,2,3,4,5,6,7,8} where 5 is col[0], 6 is col[1] and so on
        DisjointSet ds(maxRow+maxCol+1); 

        unordered_map<int,int> stoneNodes;

        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1]+maxRow+1; //just as described above about how we gonna take the col as node

            ds.unionByRank(nodeRow,nodeCol);
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }

        int cnt = 0;
        for(auto it: stoneNodes){
            if(ds.find(it.first)==it.first){
                cnt++;
            }
        }
        
        return n-cnt;
    }
};