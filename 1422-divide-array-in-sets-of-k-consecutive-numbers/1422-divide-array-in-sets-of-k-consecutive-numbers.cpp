class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k!=0) return false;

        map<int,int> mpp;
        for(auto ch: nums) mpp[ch]++;

        for(auto it: mpp){
            auto st = it.first;
            auto f = it.second;

            if(f>0){
                for(int i=0;i<k;i++){
                    if(mpp[st+i] < f) return false;
                    mpp[st+i]-=f;
                }
            }
        }
        return true;
    }
};