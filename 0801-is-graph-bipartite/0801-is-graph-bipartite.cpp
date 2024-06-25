class Solution {
public:
    bool bfs(int i,vector<vector<int>>& graph,vector<int> &color){
        queue<int> q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                if(color[it]==color[node]){
                    return false;
                }

                if(color[it]==-1){
                    color[it] = !color[node];
                    q.push(it);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(i,graph,color)==false) return false;
            }
        }
        return true;
        
    }
};