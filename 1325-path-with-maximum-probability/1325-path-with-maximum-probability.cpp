#define pii pair<double,int>
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        int i=0;

        for(auto it: edges){
            adj[it[0]].push_back({it[1],succProb[i]});
            adj[it[1]].push_back({it[0],succProb[i]});
            i++;
        }
        priority_queue<pii> pq;
        vector<double> dis(n,0);
        pq.push({1.0,start_node});
        dis[start_node] = 1.0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int node = top.second;
            double wt = top.first;

            for(auto it: adj[node]){
                double newWt = it.second;
                int newNode = it.first;

                if(wt*newWt > dis[newNode]){
                    dis[newNode] = wt*newWt;
                    pq.push({dis[newNode],newNode});
                }
            }
        }

        return dis[end_node];
    }
};