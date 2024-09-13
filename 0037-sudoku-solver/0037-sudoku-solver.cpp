class Solution {
public:
    bool check(int r, int c, vector<vector<char>>& b, char num){
        for(int i=0;i<9;i++){
            if(b[i][c]==num) return false;
            if(b[r][i]==num) return false;
            if(b[3*(r/3)+i/3][3*(c/3)+i%3]==num) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& b){
        int n = b.size();
        int m = b[0].size();

        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){

                if(b[r][c]=='.'){
                    for(char i='1';i<='9';i++){
                        if(check(r,c,b,i)){
                            b[r][c] = i;
                            if(solve(b)) return true;
                            b[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& b) {
        solve(b);
    }
};