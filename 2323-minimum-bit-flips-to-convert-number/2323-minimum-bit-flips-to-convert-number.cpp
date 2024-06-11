class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xoro = start^goal; //opposite bits will become 1 rest 0
        //now just cnt the bits that are set;
        int cnt=0;
        for(int i=0;i<31;i++){
            if(xoro & (1<<i)) cnt++;
        }
        return cnt;
    }
};