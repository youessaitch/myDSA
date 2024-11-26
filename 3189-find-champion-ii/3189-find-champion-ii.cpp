class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        set<int> st;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)  st.insert(i);
        }

        if(st.size()>1) return -1;

        return *st.begin();
    }
};