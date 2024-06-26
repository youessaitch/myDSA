class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<32;i++){
            int cnt = 0;
            for(auto it: nums){
                if((it & (1<<i))!=0) cnt++;
            }

            if(cnt%3 != 0){
                ans = ans+(1<<i);
            }
        }
        return ans;
    }
};