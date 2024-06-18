class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x = a|b;
        if(x==c) return 0;
        int ans = 0;

        for(int i=0;i<31;i++){
            bool p = a&(1<<i);
            bool q = b&(1<<i);
            if(c&(1<<i)){
                if((p|q)==0) ans++;
            }else{
                if(p && !q) ans++;
                else if(!p && q) ans++;
                else if(p && q) ans+=2;
            }
        }
        return ans;
    }
};