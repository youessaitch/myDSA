class Solution {
public:
    int passThePillow(int n, int time) {
        if(time>(2*n-2)) time = time%(2*n-2);
        if(time<=n-1) return 1+time;
        else{
            time-=n-1;
            for(int i=n;i>=0;i--){
                time--;
                if(time==0) return i-1;
            }
        }
        return -1;
    }
};