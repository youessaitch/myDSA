class Solution {
public:
    #define ll long long
    #define pii pair<ll,ll> 
    // {wt,node}

    vector<ll> djikstra(int n, int S, int E, vector<vector<pii>> &adj){
        priority_queue<pii,vector<pii>, greater<pii>> pq;
        vector<ll> dis(n,1e16);

        pq.push({0,S});
        dis[S]=0;

        while(!pq.empty()){
            ll wt = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                ll newNode = it.first;
                ll nodeWt = it.second;
                if(wt + nodeWt < dis[newNode]){
                    dis[newNode] = wt+nodeWt;
                    pq.push({dis[newNode],newNode});
                }
            }
        }
        return dis;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        ll m = edges.size();
        vector<vector<pii>> adj(n+1);
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<bool> ans(m,false);
        
        vector<ll> A = djikstra(n,0,n-1,adj); //from source to desti
        vector<ll> B = djikstra(n,n-1,0,adj); //from desto to source

        for(int i=0;i<A.size();i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;

        for(int i=0;i<A.size();i++){
            cout<<B[i]<<" ";
        }
        cout<<endl;

        ll minDist = A[n-1]; //minimum distance using djikstra
        if(minDist == 1e16) return ans;
        for(int i=0;i<m;i++){
            auto it = edges[i]; // a,b,weight
            if(A[it[0]]+B[it[1]]+it[2] == minDist || 
            A[it[1]]+B[it[0]]+it[2] == minDist){
                ans[i] = true;
            }

        }
        return ans;
    }
};