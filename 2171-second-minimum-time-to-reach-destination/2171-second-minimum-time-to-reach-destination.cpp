class Solution {
public:
    #define pi pair<int, int>

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj[n+1]; //1 to n
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        priority_queue<pi,vector<pi>, greater<pi>> pq;
        vector<int> d1(n+1,1e9); //min distance
        vector<int> d2(n+1,1e9); //second minimum

        pq.push({0,1}); //{timePassed,node} 
        d1[1] = 0;

        while(!pq.empty()){
            auto top = pq.top();
            int timePassed = top.first;
            int node = top.second;
            pq.pop();

            if(d2[n]!=1e9 && node == n) return d2[n];

            int mult = timePassed/change;
            if(mult%2==1){ // red light
                timePassed = change*(mult+1); //green light
            }

            for(auto it: adj[node]){
                if(d1[it] > timePassed+time){ //time is edge weight
                    d2[it] = d1[it];
                    d1[it] = timePassed+time;
                    pq.push({timePassed+time,it});
                }else if(d2[it]>timePassed+time && d1[it]!=timePassed+time){ //between shortest and second shortest time
                    d2[it] = timePassed+time;
                    pq.push({timePassed+time,it});
                }
            }
        }
        return -1;
    }
};