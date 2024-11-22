class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        unordered_map<string,int> mpp; //we need to store same patterns

        for(int i=0;i<n;i++){
            string temp = "";
            temp += '*';
            for(int j=1;j<m;j++){
                if(mat[i][j] != mat[i][j-1]){
                    temp+='|';
                }
                temp+='*';
            }
            mpp[temp]++;
        }

        int maxi = 0;
        for(auto it: mpp){
            maxi = max(maxi,it.second);
        }

        return maxi;

    }
};