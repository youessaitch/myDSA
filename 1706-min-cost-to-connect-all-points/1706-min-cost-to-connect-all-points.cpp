class Solution {
public:
#define pii pair<int,int>
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }

        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,0}); //wt,node

        int sum=0;
        vector<int> vis(n,0);

        while(!pq.empty()){
            auto wt = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            if(vis[node]) continue;

            vis[node]=1;
            sum+=wt;

            for(auto it: adj[node]){
                if(!vis[it[0]]) pq.push({it[1],it[0]});
            }
        }
        return sum;
    }
};