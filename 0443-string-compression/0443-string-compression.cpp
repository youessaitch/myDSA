class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, k = 0;
        while(i<chars.size()){
            int count = 1, j = i+1;
            while(j<chars.size() && chars[j] == chars[i] ){
                count++; j++;
            }
            chars[k] = chars[i];
            k++;
            if(count>1){
                string cnt = to_string(count);
                for(char ch : cnt){
                    chars[k] = ch;
                    k++;
                }

            }
            i = j; 
        }
        // return chars.size();
        return k;
    }
};