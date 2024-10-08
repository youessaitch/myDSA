class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int open = 0;
        
        for(int i=0; i<n; i++){
            if(s[i] == '[') open++;
            else if(s[i] == ']'){
                if(open > 0) open--;
            }
        }

        return (open+1)/2;
    }
};