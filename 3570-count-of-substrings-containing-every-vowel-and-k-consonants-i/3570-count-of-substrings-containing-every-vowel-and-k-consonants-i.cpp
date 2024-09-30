class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int ans = 0;
        for(int idx=0;idx<n;idx++){
            int c = 0;
            bool a = false;
            bool e = false;
            bool i = false;
            bool o = false;
            bool u = false;
            bool flag = false;
            for(int j=idx;j<n;j++){
                if(word[j]=='a') a = true;
                else if(word[j]=='e') e = true;
                else if(word[j]=='i') i = true;
                else if(word[j]=='o') o = true;
                else if(word[j]=='u') u = true;
                else{
                    c++;
                }

                if(a && e && i && o && u) flag = 1;

                if(flag && c == k) ans++;
            }
        }

        return ans;
    }
};