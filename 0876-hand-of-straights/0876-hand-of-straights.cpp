class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;

        map<int,int> mpp;
        for(auto ch: hand) mpp[ch]++;

        for(auto it: mpp){
            auto st = it.first;
            auto f = it.second;

            if(f>0){
                for(int i=0;i<groupSize;i++){
                    if(mpp[st+i] < f) return false;
                    mpp[st+i]-=f;
                }
            }
        }
        return true;
    }

};