class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size();
        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++){
            mpp[deck[i]]++;
        }

        int x = mpp.begin()->second;

        for(auto &it: mpp){
            x = __gcd(it.second,x);
        }

        if(x==1) return false;
        return true;
    }
};