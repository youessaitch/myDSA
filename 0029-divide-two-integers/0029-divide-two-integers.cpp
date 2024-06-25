class Solution {
public:
    int divide(int dividend, int divisor) {
        long long n = (long long)dividend;
        long long m = (long long)divisor;
        if(n == -2147483648 && m == -1) return 2147483647;
        return n/m;
    }
};