class Solution {
public:
    #define pi pair<int,int>
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> adj[n];
        for(int i=0;i<n;i++){ //O(n^2)
            for(int j=i+1;j<n;j++){
                int wt = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]); 
                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }

        priority_queue<pi,vector<pi>,greater<pi>> pq; //{weight,node}
        vector<int> vis(n,0);
        
        pq.push({0,0}); //initially 0 has weight of 0
        int sum = 0;
        
        //pq TC = O(E)
        while(!pq.empty()){
            auto wt = pq.top().first;
            auto node = pq.top().second;
            pq.pop(); //O(logE)
             
            if(vis[node]==1) continue;
            
            vis[node]=1;
            sum+=wt;
            
            for(auto it: adj[node]){
                auto child = it[0];
                auto child_wt = it[1];
                
                if(vis[child]==0) pq.push({child_wt,child}); //O(logE)
            }
        }
        //TC = O(n^2 * logn)
        //SC = O(N)
        return sum;
    }
};