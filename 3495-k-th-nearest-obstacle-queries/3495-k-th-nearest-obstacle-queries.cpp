class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& q, int k) {
        int m = q.size();
        vector<int> ans;
        priority_queue<int> pq;

        for(int i=0;i<m;i++){
            int x = q[i][0];
            int y = q[i][1];
            int dis = abs(x) + abs(y);
            pq.push(dis);
            if(pq.size()<k){
                ans.push_back(-1);
                continue;
            }else{
                while(pq.size()>k) pq.pop();
                ans.push_back(pq.top());
            }
        }
        return ans;
    }
};