class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int cnt = 0;
        int len = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i] == maxi){
                cnt++;
            }else{
                len = max(len,cnt);
                cnt=0;
            }
        }

        len = max(len,cnt);
        return len;
    }
};