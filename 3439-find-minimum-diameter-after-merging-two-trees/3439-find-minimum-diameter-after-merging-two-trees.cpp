class Solution {
public:
    int dfs(int u, int pu, int &maxDiameter, vector<vector<int>> &graph){
        int tallest = 0, secondTallest = 0; //calc tallest & second tallest from a node and add 1 to find the diameter
        for(auto v: graph[u]){
            if(v!=pu){
                int h = dfs(v,u,maxDiameter,graph);
                if(h >= tallest){
                    secondTallest = tallest;
                    tallest = h;
                }else if(h>=secondTallest){
                    secondTallest = h;
                }
            }
        }
        maxDiameter = max(maxDiameter,tallest + secondTallest);
        return 1 + max(tallest,secondTallest);
    }

    int findDiameter(vector<vector<int>> &edges){
        int n = edges.size()+1;
        vector<vector<int>> graph(n);
        for(auto it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        int maxDiameter = 0;
        dfs(0,-1,maxDiameter,graph);
        return maxDiameter;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // n = edges1.size();
        // m = edges2.size();
        int D1 = findDiameter(edges1);
        int D2 = findDiameter(edges2);
        int newDiameter = 1 + (D1+1)/2 + (D2+1)/2;
        return max({D1,D2,newDiameter});

    }
};