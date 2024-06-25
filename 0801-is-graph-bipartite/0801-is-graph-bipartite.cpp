class Solution {
public:
    bool dfs(int curr, vector<vector<int>>& graph, vector<int>& color, int currcolor) {
        color[curr] = currcolor;

        for (auto it : graph[curr]) {
            if (color[it] == currcolor) return false;

            if (color[it] == -1) {
                if (dfs(it, graph, color, 1 - currcolor) == false) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // Initialize all colors to -1

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (dfs(i, graph, color, 1) == false) return false;
            }
        }
        return true;
    }
};
