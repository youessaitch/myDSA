class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        //aababbab
        //aabbbbbb

        //bbaaaaabb
        //bbbbbbbbb
        //aaaaaaabb
        vector<int> cnta(n);
        vector<int> cntb(n);
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
        // for(int i=0;i<n;i++){
        //     cout<<cnta[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<cntb[i]<<" ";
        // }
        // cout<<endl;

        int mini = 1e9;
        int temp = 0;
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