class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double waiting = 0;
        int time = 0;
        for(auto it: customers){
            int arrival = it[0];
            int prep = it[1];
            if(time == 0){
                time = (arrival + prep);
                waiting += time - arrival;
                continue;
            }

            if(arrival<=time){
                time += prep;
                waiting += time - arrival;
            }else{
                time += (arrival-time + prep);
                waiting += prep;
            }


        }
        double ans = waiting/(double)n;
        return ans;
    }
};