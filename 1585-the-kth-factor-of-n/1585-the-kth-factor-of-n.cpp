class Solution {
public:
    int kthFactor(int n, int k) {
        if(k>n) return -1;
        int f = 0;
        int ans = -1;
        for(int i=1;i<=n;i++){
            if(n%i==0){ 
                // ans = i;
                f++;}
            if(f==k){ 
                ans = i;
                break;}
        }
        return ans;
    }
};