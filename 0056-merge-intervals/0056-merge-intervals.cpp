class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            // if(i<n-1 && intervals[i+1][0]>intervals[i][1]){ 
                
            // }
            if(i<n-1 && end>=intervals[i+1][0]){
                end = max(end,intervals[i+1][1]);
            }else if(i<n-1 && end<intervals[i+1][0]){
                ans.push_back({start,end});
                start = intervals[i+1][0];
                end = intervals[i+1][1];
            }
        }

        if(start!=-1 && end!=0)
            ans.push_back({start,end});

        return ans;
    }
};