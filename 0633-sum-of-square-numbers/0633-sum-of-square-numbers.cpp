class Solution {
public:
    #define ll long long int
    #define ld long double
    bool judgeSquareSum(int c) {
        ll i = 1;
        ll j = sqrt(c);
        ld h = sqrt(c);
        if(j==h) return true;
        while(i<=j){
            if(i*i+j*j==c){
                return true;
            }else if(i*i+j*j>c){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};