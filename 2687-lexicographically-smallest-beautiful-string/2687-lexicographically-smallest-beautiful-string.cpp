//Asked in google OA
// There should not exist palindromes of length two or three
//  0 1 2
//  a b a (aba will form a palindrome)

// 0 1
// a a (aa will form a palindrome)
class Solution {
public:
    void calculate(string &s, int start, int k) {
        int n = s.size();

        for (int i = start; i < n; i++) { //start from i+1 to n where i is the index jaha mereko palindrome nhi mila to hum ok me ghus gye the 
            for (char ch = 'a'; ch < 'a' + k; ch++) {
                if (i == start && ch >= s[i]) break;
                bool ok = true;
                if (i - 2 >= 0) {
                    if ((ch == s[i - 1]) || (ch == s[i - 2])) {
                        ok = false;
                    }
                } else if (i - 1 >= 0) {
                    if (ch == s[i - 1]) {
                        ok = false;
                    }
                }

                if (ok == true) {
                    s[i] = ch;
                    break;
                }
            }
        }
    }

    string smallestBeautifulString(string s, int k) {
        int n = s.size();

        //R->L
        for (int i = n - 1; i >= 0; i--) {
            //check badha kr (a->b)
            for (char ch = s[i] + 1; ch < 'a' + k; ch++) {
                bool ok = true; //flag
                if (i - 2 >= 0) { // i-1 i-2 dono me se koi palindrome nhi banan chaiye with i
                    if ((ch == s[i - 1]) || (ch == s[i - 2])) {
                        ok = false;
                    }
                } else if (i - 1 >= 0) { // i-1 should not form palindrome with i
                    if (ch == s[i - 1]) {
                        ok = false;
                    }
                }
                
                // if palindrome nhi bn rha to we can have the answer
                if (ok == true) {
                    s[i] = ch;
                    calculate(s, i + 1, k);
                    return s;
                }
            }
        }
        return "";
    }
};
