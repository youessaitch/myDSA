class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int ans = -1e5;

        for(int i=0;i<n;i++){
            int temp = 0;
            int t= 1;
            for(int j=i;j<n;j++){
                temp += satisfaction[j]*t;
                t++;
            }
            ans = max(ans,temp);
        }
        if(ans < 0) return 0;
        return ans;
    }
};