class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int ans = 0;
        for(int bit = 0; bit<32; bit++){
            int mask = 1<<bit;
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(candidates[i]&mask) cnt++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};