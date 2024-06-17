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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        // Determine the maximum row and column indices
        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        // Create a DisjointSet large enough to handle rows and columns as nodes
        //we are making the ds 1D by taking rows as nodes then taking col values ie row = {0 1 2 3 4}, col={0,1,2,3}; then we will take as {0,1,2,3,4,5,6,7,8} where 5 is col[0], 6 is col[1] and so on
        DisjointSet ds(maxRow + maxCol + 1);

        unordered_map<int, int> stoneNodes; //cnt unique rows and cols

        // Union operation for each stone
        for (auto& stone : stones) {
            int nodeRow = stone[0];
            int nodeCol = stone[1] + maxRow + 1; ///just as described above about how we gonna take the col as node

            ds.unionByRank(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        // Count the number of unique components
        int cnt = 0;
        for (auto& node : stoneNodes) {
            if (ds.find(node.first) == node.first) {
                cnt++;
            }
        }

        // The number of stones that can be removed is total stones minus the number of unique components
        return n - cnt;
    }
};