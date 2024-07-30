class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        //aababbab
        
        vector<int> cnta(n); //prefix sum for a
        vector<int> cntb(n); //prefix sum for b

        //cnt prefix sum
        for(int i=0;i<n;i++){ 
            if(i==0){
                if(s[i]=='a') cnta[i] = 1;
                else if(s[i]=='b') cntb[i] = 1;
            }else{
                if(s[i] == 'a') {
                    cnta[i] = cnta[i-1]+1;
                    cntb[i] = cntb[i-1];   
                }
                else if(s[i]=='b') {
                    cntb[i] = cntb[i-1]+1;
                    cnta[i] = cnta[i-1];
                }
            }
        }

        int mini = 1e9;
        int temp = 0;

        // temp = (number of 'b' before it + number of 'a' after it)
        for(int i=0;i<n;i++){
            if(i==0){
                temp = cnta[n-1]-cnta[i];
                mini = min(mini,temp);
            }else{
                temp = (cnta[n-1]-cnta[i]) + cntb[i-1];
                mini = min(mini,temp);
            }
        }
        return mini;
    }
};