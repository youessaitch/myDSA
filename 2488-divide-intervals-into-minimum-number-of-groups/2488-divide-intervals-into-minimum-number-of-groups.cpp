class Solution {
public:
    // Line Sweep Algorithm
    // No of groups required == Maximum number of overlapping intervals
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        //max(a1,a2) < min(b1,b2) ---> intersecting [No use here], we using line sweep algorithm

        vector<pair<int,int>> v;

        for(auto it: intervals){
            v.push_back({it[0],1}); //start time, +1
            v.push_back({it[1]+1,-1}); //end time, -1
        }

        sort(v.begin(),v.end()); 

        for(auto it: v){
            cout<<it.first<<" "<<it.second<<endl;
        }

        int cnt = 0;
        int maxi = 1;

        for(auto it: v){
            if(it.second == 1){
                cnt+=1;
            }else{
                cnt-=1;
            }

            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};