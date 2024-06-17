	// class DisjointSet {
	// public:
	//     vector<int> rank, parent;
	
	//     DisjointSet(int n) {
	//         rank.resize(n + 1, 0);
	//         parent.resize(n + 1);
	//         for (int i = 0; i <= n; i++) {
	//             parent[i] = i;
	//         }
	//     }
	
	//     int find(int node) {
	//         if (node == parent[node])
	//             return node;
	//         return parent[node] = find(parent[node]);
	//     }
	
	//     void unionByRank(int u, int v) {
	//         int ulp_u = find(u);
	//         int ulp_v = find(v);
	//         if (ulp_u == ulp_v) return;
	
	//         if (rank[ulp_u] < rank[ulp_v]) {
	//             parent[ulp_u] = ulp_v;
	//         } else if (rank[ulp_v] < rank[ulp_u]) {
	//             parent[ulp_v] = ulp_u;
	//         } else {
	//             parent[ulp_v] = ulp_u;
	//             rank[ulp_u]++;
	//         }
	//     }
	// };


class Solution {
public:
    void dfs(int node, vector<vector<int>>& stones, vector<int> &vis){
        vis[node]=1;
        for(int i=0;i<stones.size();i++){
            if(!vis[i] && (stones[node][0]==stones[i][0] || stones[node][1]==stones[i][1])){
                dfs(i,stones,vis);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,stones,vis);
                cnt++;
            }
        }

        return n - cnt;


        // int n = stones.size();
        // DisjointSet ds(n);

        // // int cnt = 0;
        // // vector<int> vis(n,0);
        // vector<int> cnt_nodes;
        // int cnt = 0;

        // for(int i=0;i<n;i++){
        //     int x1 = stones[i][0];
        //     int y1 = stones[i][1];
        //     // vis[i]=1;
        //     cnt=0;
        //     for(int j=i+1;j<n;j++){
        //         int x2 = stones[j][0];
        //         int y2 = stones[j][1];

        //         // if(ds.find(i)==ds.find(j)) continue;

        //         if(x1==y1 || x2==y2 ){
        //             ds.unionByRank(i,j);
        //             // vis[j]=1;
        //             cnt++;
        //         }
        //     }
        //     cnt_nodes.push_back(cnt);
        // }

        // int ans = 0;
        // for(auto it: cnt_nodes){
        //     ans += (it-1);
        // }

        // return ans;

        
    }
};