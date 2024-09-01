class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int t=0;
        vector<vector<int>> v(m,vector<int>(n,0));
        int hehe = m*n;
        if(hehe!=original.size()) return {};
        int ele = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v[i][j] = original[i*n+j];
                ele++;
            }
        }
        if(ele != original.size()) return {};
        return v;
    }
};