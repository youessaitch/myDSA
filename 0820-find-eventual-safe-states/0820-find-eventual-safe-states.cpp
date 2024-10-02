class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> revAdj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                revAdj[graph[i][j]].push_back(i);
            }
        }

        vector<int> indegree(n,0); //outdegree for original graph

        for(int i=0;i<n;i++){
            for(auto it: revAdj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it: revAdj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};