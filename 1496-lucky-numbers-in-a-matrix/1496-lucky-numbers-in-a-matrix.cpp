class Solution {
public:
    int n,m;
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int maxi = -1e5;
                int mini = 1e5;
                int num = matrix[i][j];
                for(int k=0;k<n;k++){
                    maxi = max(maxi,matrix[k][j]);
                }
                for(int k=0;k<m;k++){
                    mini = min(mini,matrix[i][k]);
                }
                if(maxi == num && mini == num) ans.push_back(num);
            }
        }
        return ans;
    }
};