#define pii pair<int,int>
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> adj[n];
        // 0 -> n-1
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }

        vector<int> ans;

        for(int i=0;i<m;i++){
            auto t = queries[i];
            int u = t[0];
            int v = t[1];
            adj[u].push_back(v);

            vector<int> dis(n,1e9);
            priority_queue<pii,vector<pii>,greater<pii>> pq;
            pq.push({0,0}); //{dis,node}
            dis[0]=0;
            int cnt = 0;

            while(!pq.empty()){
                auto top = pq.top();
                pq.pop();
                int wt = top.first;
                int node = top.second;

                for(auto it: adj[node]){
                    if(1 + wt < dis[it]){
                        dis[it] = 1 + wt;
                        pq.push({dis[it],it});
                    }
                }
            }

            ans.push_back(dis[n-1]);
        }

        return ans;
    }
};