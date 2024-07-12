class Solution {
public:
    int n,m;

    vector<vector<int>> prefixMaker(vector<vector<char>>& grid, char ch){
        vector<vector<int>> prefix(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix[i][j] = (grid[i][j]==ch);

                if(i>0) prefix[i][j] += prefix[i-1][j];
                if(j>0) prefix[i][j] += prefix[i][j-1];
                if(i>0 && j>0) prefix[i][j] -= prefix[i-1][j-1];
            }
        }
        return prefix;
    }

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> xCount = prefixMaker(grid,'X');
        vector<vector<int>> yCount = prefixMaker(grid,'Y');

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans += ((xCount[i][j] == yCount[i][j]) && xCount[i][j] > 0);
            }
        }
        return ans;
    }
};