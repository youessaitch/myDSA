class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        // if(n==1) return cost[0];
        // if(n==2) return cost[0]+cost[1];
        sort(cost.begin(),cost.end(),greater<int>());
        int total = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(cnt<2)total += cost[i];
            if(cnt==2){
                cnt=0;
                continue;
            }
            cnt++;
        }
        return total;
    }
};