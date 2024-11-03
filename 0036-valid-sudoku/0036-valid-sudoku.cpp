class Solution {
public:
    int n = 9;
    bool isValidSudoku(vector<vector<char>>& grid) {

        for(int i=0;i<9;i++){
            unordered_map<char,int> row;
            unordered_map<char,int> col;
            for(int j=0;j<9;j++){
                if(grid[i][j] != '.'){
                    if(row.find(grid[i][j])!=row.end()) return false;
                    else row[grid[i][j]]++;
                }

                if(grid[j][i] != '.'){
                    if(col.find(grid[j][i])!=col.end()) return false;
                    else col[grid[j][i]]++;
                }
            }
        }

        unordered_map<int,unordered_map<int,int>> box;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(grid[i][j]!='.'){
                    int boxInd = 3*(i/3) + j/3;
                    if(box[boxInd].find(grid[i][j])!=box[boxInd].end()) return false;
                    else box[boxInd][grid[i][j]]++;
                }
            }
        }
        return true;
    }
};