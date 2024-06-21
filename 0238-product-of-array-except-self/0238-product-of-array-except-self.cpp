class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int huh0 = 1;
        int huhn0 = 1;
        int z = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)z++;
            if(nums[i]!=0)
                huhn0*=nums[i];
            huh0*=nums[i];
        }

        if(z>1){
            // ans.push_back(n,0);
            return ans;
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=0)
                ans[i]=(huh0/nums[i]);
            else{
                ans[i]=(huhn0);
            }
        }
        return ans;
    }
};