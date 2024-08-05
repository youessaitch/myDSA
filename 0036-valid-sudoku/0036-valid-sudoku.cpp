class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;

        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> hori;
            unordered_map<char, int> vert;

            for (int j = 0; j < 9; j++) {
                // Check row
                if (board[i][j] != '.') {
                    if (hori.find(board[i][j]) != hori.end()) return false;
                    else hori[board[i][j]]++;
                }

                // Check column
                if (board[j][i] != '.') {
                    if (vert.find(board[j][i]) != vert.end()) return false;
                    else vert[board[j][i]]++;
                }
            }
        }

        // Check 3x3 sub-boxes
        unordered_map<int,unordered_map<char,int>> box;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int boxIdx = 3*(i/3) + (j/3);
                if (box[boxIdx].find(board[i][j]) != box[boxIdx].end()) return false;
                else box[boxIdx][board[i][j]]++;
            }
        }

        return true;
    }
};
