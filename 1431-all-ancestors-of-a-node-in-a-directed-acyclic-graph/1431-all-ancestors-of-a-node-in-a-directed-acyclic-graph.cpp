class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n,vector<int>(0));
        //u->v then indegree[v]++;
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        for(int i=0;i<indegree.size();i++){
            cout<<indegree[i]<<" ";
        }

        vector<set<int>> ans(n); //to avoid duplicate

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto v: adj[u]){
                indegree[v]--;
                ans[v].insert(u);
                for(auto it: ans[u]){ //include all the nodes from the parent too 
                    ans[v].insert(it);
                }
                if(indegree[v]==0) q.push(v);
            }
        }

        vector<vector<int>> res(n);
        for(int i=0;i<n;i++){
            res[i] = vector<int>(ans[i].begin(),ans[i].end());
        }
        return res;
        
    }
};