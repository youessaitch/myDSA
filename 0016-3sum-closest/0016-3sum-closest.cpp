class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mini = 1e6;
        for(int i=0;i<n-2;i++){
            int j=i+1, k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];

                if(sum == target) return sum;
                
                if(sum<target) j++;
                else k--;

                if(abs(sum-target) < abs(mini-target)){
                    mini = sum;
                }

            }
            
        }
        return mini;
    }
};