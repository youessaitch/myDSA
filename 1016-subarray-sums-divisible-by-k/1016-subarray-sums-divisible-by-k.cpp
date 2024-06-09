class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefmod(n,0); //store prefix % k
        int cnt = 0; //to store the ans
        int pref = 0; // store prefix sum
        unordered_map<int,int> mpp; //to have a cnt of number of same element in prefmod

        //store prefix sum
        for(int i=0;i<n;i++){
            pref += nums[i];
            prefmod[i]=(pref % k);
            if(prefmod[i]<0) prefmod[i]+=k; // eg. -2 mod 6 = 4
            mpp[prefmod[i]]++;
        }

        //iterate the map
        for(auto it: mpp){
            if(it.second>1){ //a number appears more than once
                int temp = (it.second-1); 
                cnt += (temp*(temp+1))/2; //cnt number of distinct pairs that can be formed (simple math)
            }
            if(it.first==0){ //if the prefmod happens to be 0 then the whole subarray from index 0 to the index where prefmod == 0 should be considered as well
                cnt+=it.second; 
            }
        }
        return cnt; 

        //pref[]= 4 9 9 7 4 5
        //mod[] = 4 4 4 2 4 0
        // map: 4->4   , cnt = 3+2+1 = (it.second-1)*(it.second-1+1)/2;
        //      2->1    , cnt = 0
        //      0->1    , cnt = 1;
        // ans = 6+0+1 = 7;
    }
};