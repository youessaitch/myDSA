class Solution {
public:
    //Kadane's
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int p = 1;
        int s = 1;

        int maxi = INT_MIN;

        //left to right
        for(int i=0;i<n;i++){
            p*=nums[i];
            maxi = max(maxi,p);
            if(p==0) p=1;
        }

        //right to left
        for(int i=n-1;i>=0;i--){
            s*=nums[i];
            maxi = max(maxi,s);
            if(s==0) s=1;
        }

        return maxi;
    }
};