class Solution {
public:
    int findTheWinner(int n, int k) {
        // vector<int> v(n,1);
        // int t = n;
        // int i = 0;
        // int K = k;
        // while(t>1){ //n
        //     while(K!=1){
        //         if(v[i%n]==-1){
        //             i++;
        //             continue;
        //         }
        //         i++;
        //         K--;
        //     }
        //     while(v[i%n]==-1) i++;
            
        //     if(K==1){
        //         t--;
        //         v[i%n]=-1;
        //         i++;
        //         K=k;
        //     }
        // }

        // for(int i=0;i<n;i++){
        //     if(v[i]==1) return i+1;
        // }
        // return -1;
        int ans = 1;
        for(int i=2;i<=n;i++){
            ans = (ans + (k-1))%i+1;
        }
        return ans;
    }
};