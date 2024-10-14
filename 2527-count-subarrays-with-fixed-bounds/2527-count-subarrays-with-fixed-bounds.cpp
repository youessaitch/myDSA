class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        
        int i=0;

        long long ans = 0;

        while(i<n){

            if(i<n && nums[i]<minK || nums[i]>maxK){
                i++;
                continue;
            }

            int j = i;

            while(j<n && nums[j]>=minK && nums[j]<=maxK){
                j++;
            }

            int k = i;
            int cntmx = 0;
            int cntmn = 0;

            while(k<j){
                
                if(cntmx>0 && cntmn>0){
                    ans += (j-k+1);

                    if(nums[i] == minK){
                        cntmn--;
                    }
                    if(nums[i] == maxK){
                        cntmx--;
                    }
                    i++;
                }else{
                    if(nums[k] == minK) cntmn++;
                    if(nums[k] == maxK) cntmx++;
                    k++;
                }
            }

            while(i<j && cntmx>0 && cntmn>0){
                ans++;
                if(nums[i] == minK) cntmn--;
                if(nums[i] == maxK) cntmx--;
                i++;
            }

            i=j;
        }

        return ans;
    }
};