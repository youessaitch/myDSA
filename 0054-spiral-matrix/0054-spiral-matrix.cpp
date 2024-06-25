class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // vector<vector<int>> ans(n,vector<int>(m));
        vector<int> v;
        int cnt = 0;
        int l=0,r=n-1,t=0,b=m-1;

        int total = n*m;
        while(cnt<total){
            for(int i=l;i<=r && cnt<total;i++){
                v.push_back(matrix[t][i]);
                cnt++;
            }
            t++;
            for(int i=t;i<=b && cnt<total;i++){
                v.push_back(matrix[i][r]);
                cnt++;
            }
            r--;
            for(int i=r;i>=l && cnt<total;i--){
                v.push_back(matrix[b][i]);
                cnt++;
            }
            b--;

            for(int i=b;i>=t && cnt<total;i--){
                v.push_back(matrix[i][l]);
                cnt++;
            }
            l++;
        }
        return v;
    }
};