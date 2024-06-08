class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // 23 25 31 35 42
        //k = 13
        // 10 12 5 9 3

        //23 25 29 35 42
        //k=6
        //5 1 5 5 0
        int n = nums.size();
        vector<int> pref(n,0);
        vector<int> prefmod(n,0);
        pref[0] = nums[0];
        prefmod[0] = pref[0]%k;
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+nums[i];
            prefmod[i] = pref[i]%k;
        }

        unordered_map<int,int> mpp; //prefmod, index
        mpp[0]=-1;

        for(int i=0;i<n;i++){
            if(mpp.find(prefmod[i])!=mpp.end()){
                if(i - mpp[prefmod[i]]>1) return true;
            }else{
                mpp[prefmod[i]] = i;
            }
        }

        return false;

        //1 3 15
        //k=6
        //1 3 3
        
    }
};