class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;

        //create a new extended array (nums+nums)
        vector<int> newNums;
        newNums = nums;
        newNums.insert(newNums.end(),nums.begin(),nums.end());
        int m = newNums.size();
    
        vector<int> pref(m,0); //prefix for '0'

        for(auto it: nums){ //cnt 1's -> sliding window size
            if(it==1) ones++;
        }
        
        //calculate number of zeroes upto each index
        for(int i=0;i<m;i++){
            if(i==0){
                if(newNums[i]==0) pref[i]=1;
            }else{
                if(newNums[i]!=0) pref[i]=pref[i-1];
                else pref[i]=pref[i-1]+1;
            }
        }

        if(ones==0) return 0; //if no ones return 0

        // for(int i=0;i<n;i++){
        //     cout<<pref[i]<<" ";
        // }

        int l=0;
        int r=ones-1;        
        int ans = 1e9;

        //sliding window
        while(r<m){
            int zero;
            if(l==0) zero = pref[r];
            else zero = pref[r] - pref[(l-1)];
            ans = min(ans,zero);
            l++;
            r++;
        }
        return ans;
    }
};