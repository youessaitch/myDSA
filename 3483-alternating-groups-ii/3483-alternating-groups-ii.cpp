class Solution {
public:
    // bool check(deque<int> &s, int k){
    //     bool ch = true;
    //     for(int i=1;i<k-1;i++){
    //         if(s[i]!=s[i-1] && s[i]!=s[i+1]) continue;
    //         else{
    //             ch = false;
    //             break;
    //         }
    //     }
    //     return ch;
    // }

    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int cnt = 1;
        int prev = colors[0];
        int ans = 0;
        for(int i=1;i<n+k-1;i++){
            if(colors[i%n]!=prev) cnt+=1;
            else cnt = 1;

            if(cnt>=k) ans++;
            prev = colors[i%n];
        }
        return ans;
    }
};