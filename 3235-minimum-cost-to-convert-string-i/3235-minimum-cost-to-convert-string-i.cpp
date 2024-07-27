class Solution {
public:
typedef pair<int, int> pi; // {wt, node}

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, int> charToIndex; // Map character to index
        int index = 0;

        // Assign an index to each unique character
        for (char c : original) {
            if (charToIndex.find(c) == charToIndex.end()) {
                charToIndex[c] = index;
                index++;
            }
        }
        for (char c : changed) {
            if (charToIndex.find(c) == charToIndex.end()) {
                charToIndex[c] = index;
                index++;
            }
        }

        int n = charToIndex.size();
        vector<vector<long long>> dis(n, vector<long long>(n, 1e9));
        for (int i = 0; i < n; i++) {
            dis[i][i] = 0; // Self distance 0
        }

        for (int i = 0; i < original.size(); i++) {
            int u = charToIndex[original[i]];
            int v = charToIndex[changed[i]];
            dis[u][v] = min(dis[u][v], (long long)cost[i]);
        }

        // Floyd-Warshall algorithm
        // i->via->j : min cost to reach j from i by via
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dis[i][via] < 1e9 && dis[via][j] < 1e9)
                        dis[i][j] = min(dis[i][j], dis[i][via] + dis[via][j]);
                }
            }
        }

        long long total = 0;
        int m = source.size();
        if (target.size() != m) return -1;

        for (int i = 0; i < m; i++) {
            if (source[i] == target[i]) continue;
            if (charToIndex.find(source[i]) == charToIndex.end() || charToIndex.find(target[i]) == charToIndex.end()) {
                return -1; // If source[i] or target[i] does not exist in the graph
            }
            int u = charToIndex[source[i]];
            int v = charToIndex[target[i]];
            long long path = dis[u][v];
            if (path == 1e9) return -1; // If no path is found
            total += path;
        }

        return total;
    }
};