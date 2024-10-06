class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {
        int n = op.size();
        
        if(k==1) return 'a';

        long long newK = -1;
        long long len = 1;
        int opType = -1;

        for(int i=0;i<n;i++){
            len*=2;
            
            if(len>=k){
                opType = op[i];
                newK = k - len/2;
                break;
            }
        }

        char ch = kthCharacter(newK, op);

        if(opType == 0) return ch;

        return (ch == 'z')? 'a' : ch+1;
    }
};