class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> grid(n);
        int idx = 0;
        for(int j=0;j<n;j++){
            vector<int> temp;
            for(int i=n-1;i>=0;i--){
                temp.push_back(matrix[i][j]);
            }
            grid[idx] = temp;
            idx++;
        }

        matrix = grid;
        // return matrix;
        
    }
};