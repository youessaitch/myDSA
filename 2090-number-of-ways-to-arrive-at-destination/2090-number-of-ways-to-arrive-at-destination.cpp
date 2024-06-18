class Solution {
public:
    #define ll long long
    #define pi pair<ll,ll>
    int countPaths(int n, vector<vector<int>>& roads) {
        const ll MOD = 1e9 + 7;
        vector<pair<int, int>> adj[n];

        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        priority_queue<pi, vector<pi>, greater<pi>>  pq; //min heap

        vector<ll> dis(n, LONG_MAX); 
        vector<ll> ways(n, 0); //it will cnt number of ways i can reach at a node

        pq.push({0, 0});
        dis[0] = 0;
        ways[0] = 1; //can reach node 0 in only 1 way (initially since starting from 0 only)

        while(!pq.empty()){
            ll wt = pq.top().first;
            ll node = pq.top().second;

            pq.pop();

            if (wt > dis[node]) continue;

            for(auto it : adj[node]){
                ll nxt_node = it.first;
                ll new_wt = it.second;

                if(dis[nxt_node] > wt + new_wt){
                    dis[nxt_node] = wt + new_wt;
                    ways[nxt_node] = ways[node]; //ways to reach current node = ways to reach previous node
                    pq.push({dis[nxt_node], nxt_node});
                }
                 else if (dis[nxt_node] == wt + new_wt) {
                    ways[nxt_node] = (ways[nxt_node] + ways[node]) % MOD; //if same then just increase the number of ways

                }
            }
        }

        return ways[n-1]% MOD; //return no of ways to reach n-1
    }
};