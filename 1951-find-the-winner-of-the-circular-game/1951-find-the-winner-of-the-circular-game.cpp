class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n,1);
        int t = n;
        int i = 0;
        int K = k;
        while(t>1){
            while(K!=1){
                if(v[i%n]==-1){
                    i++;
                    continue;
                }
                i++;
                K--;
            }
            while(v[i%n]==-1) i++;
            
            if(K==1){
                t--;
                v[i%n]=-1;
                i++;
                K=k;
            }
        }

        for(int i=0;i<n;i++){
            if(v[i]==1) return i+1;
        }
        return -1;
    }
};