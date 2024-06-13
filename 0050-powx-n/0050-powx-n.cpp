class Solution {
public:
    double myPow(double x, int m) {
        double ans = 1;
        long long n=m;
        if(n<0){ 
            x = 1.0/x;
            n=-n;
            }
        while (n > 0)
        {
            if (n & 1)
                ans = (ans * 1LL * x);
            x = (x * 1LL * x);
            n >>= 1;
        }
        return ans;
    }
};