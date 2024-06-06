class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k!=0) return false;

        map<int,int> mpp;
        for(auto ch: nums) mpp[ch]++;

        while(mpp.size() > 0){
            auto it = mpp.begin();
            auto st = it->first;
            if (mpp[st] == 0) continue;
            for(int i=0;i<k;i++){
                if(mpp[st+i]>0){ 
                    mpp[st+i]--;
                    if(mpp[st+i]==0) 
                        mpp.erase(st+i);
                }else return false;
            }
        }
        return true;
    }
};