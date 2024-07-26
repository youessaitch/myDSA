class Solution {
public:
    #define pi pair<int,int>

    int djikstra(int n, vector<vector<pi>> &adj, int S, int &distanceThreshold){
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        vector<int> dis(n,1e9);
        dis[S] = 0;
        pq.push({0,S});
        while(!pq.empty()){
            auto t = pq.top();
            int wt = t.first;
            int node = t.second;
            pq.pop();

            for(auto it: adj[node]){
                int newNode = it.first;
                int newWt = it.second;
                if(wt + newWt < dis[newNode]){
                    dis[newNode] = wt+newWt;
                    pq.push({wt+newWt,newNode});
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(i==S) continue;
            if(dis[i] <= distanceThreshold) cnt++;
        }
        return cnt;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pi>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        } 
        int mini = 1e9;
        int ans = 0;
        for(int i=0;i<n;i++){
            int cnt = djikstra(n, adj, i, distanceThreshold);
            if(cnt<=mini){
                mini = cnt;
                ans = i;
            }
        }
        return ans;
    }
};