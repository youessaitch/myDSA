class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> grid;
        for(int j=0;j<n;j++){
            vector<int> t;
            for(int i=n-1;i>=0;i--){
                t.push_back(matrix[i][j]);
            }
            grid.push_back(t);
        }
        
        matrix = grid;
    }
};