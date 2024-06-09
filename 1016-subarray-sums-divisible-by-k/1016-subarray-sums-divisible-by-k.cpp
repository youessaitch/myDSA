class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // int n = nums.size();
        // vector<int> pref(n,0); 
        // vector<int> prefmod(n,0); 
        // pref[0] = nums[0];
        // prefmod[0] = pref[0]%k;
        // int cnt = 0;
        // for(int i=1;i<n;i++){
        //     pref[i] = pref[i-1]+nums[i];
        //     prefmod[i] = pref[i]%k;
        //     if(nums[i]%k==0) cnt++;
        // }

        // unordered_map<int,int> mpp; //prefmod, index
        // mpp[0]=-1;

        // for(int i=0;i<n;i++){
        //     if(mpp.find(prefmod[i])!=mpp.end()){
        //         if(i - mpp[prefmod[i]]>1){
        //             cnt++;
        //         }
        //     }else{
        //         mpp[prefmod[i]] = i;
        //     }
        // }

        // return cnt;

        int n = nums.size();
        vector<int> pref(n,0);
        vector<int> prefmod(n,0);
        int cnt = 0;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            if(i==0){ 
                pref[0]=nums[0];
                prefmod[0]=(pref[0]%k);
                if(prefmod[0]<0) prefmod[0]+=k;
                // cout<<prefmod[0]<<" ";
                mpp[prefmod[0]]++;
            }
            else{
                pref[i]=pref[i-1]+nums[i];
                prefmod[i]=(pref[i]%k);
                if(prefmod[i]<0) prefmod[i]+=k;
                // cout<<prefmod[i]<<" ";
                mpp[prefmod[i]]++;
            }
        }

        for(auto it: mpp){
            if(it.second>1){
                int temp = (it.second-1);
                cnt += (temp*(temp+1))/2;
            }
            if(it.first==0){
                cnt+=it.second;
            }
        }
        return cnt;

        //pref[]= 4 9 9 7 4 5
        //mod[] = 4 4 4 2 4 0
    }
};