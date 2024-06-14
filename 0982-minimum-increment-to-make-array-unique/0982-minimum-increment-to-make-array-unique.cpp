class Solution {
public:
#define ll long long int
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //1 1 2 2 3 7
        //3 
        // map<ll,ll> mpp;
        // for(auto it: nums) mpp[it]++; //nlogn
        ll cnt = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                cnt+= nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1]+1;
            }
        }

        return cnt;
        // bool ch = false;
        // ll j;

        
        // for(auto it=mpp.begin();it!=mpp.end();it++){ //
        //     // int j = it.first;
        //     if(!ch){
        //         j = it->first;
        //         ch = true;
        //     }
        //     while(it->second > 1){
        //         for(ll k = j;k<=1e6;k++){ 
        //             if(mpp.find(k)==mpp.end()){
        //                 cnt += k - it->first;
        //                 it->second--;
        //                 mpp[k]++;
        //                 j=k+1;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return cnt;
    }
};