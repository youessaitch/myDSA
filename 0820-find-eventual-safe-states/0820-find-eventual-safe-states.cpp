class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<int> Revadj[n]; //stores linked list
        //we need to work with outdegree, so lets just make reverse list, that way we can work with indegree ( since reversed)

        //Note : if adj is x[0]->x[1], we write indegree for x[1] and not x[0], so indegree[x[1]]++;
        vector<int> indegree(n, 0);
        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                Revadj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: Revadj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};