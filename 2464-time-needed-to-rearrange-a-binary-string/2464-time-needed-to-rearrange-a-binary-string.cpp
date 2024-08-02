class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        int ones=0;
        int ans = 0;
        while(1){
            bool flag = 1;
            for(int i=0;i<n-1;i++){
                if(s[i]=='0' && s[i+1]=='1'){
                    s[i] = '1';
                    s[i+1] = '0';
                    i++;
                    flag = 0;
                }
            }

            if(flag) break;
            ans++;
        }
        return ans;
        // string temp = "";
        // for(auto it: s){
        //     if(it=='1'){ 
        //         temp += '1';
        //         ones++;
        //     }
        // }
        // int zeroes = n-ones;
        // while(zeroes){
        //     temp+='0';
        //     zeroes--;
        // }
        // int ans = 0;
        // for(int i=0;i<n;i++){
        //     if(s[i]!=temp[i]) ans++;
        // }
        // return ans;

    }
};