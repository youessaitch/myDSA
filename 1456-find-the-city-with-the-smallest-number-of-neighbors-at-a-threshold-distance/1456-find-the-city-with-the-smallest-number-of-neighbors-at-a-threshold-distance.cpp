class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n, vector<int>(n, 1e5));
        for(auto it: edges){
            int i = it[0];
            int j = it[1];
            int w = it[2];
            grid[i][j]=w; //undirected
            grid[j][i]=w; //undirected
        }

        //floyd warshall

        for(int via=0;via<n;via++){ //main part
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    
                    grid[i][j] = min(grid[i][j], grid[i][via]+grid[via][j]);
                    //i->via then via->j
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][i]=0; //diagonal values should be zero since 0->0 jane ka distance = 0, 1->1 also 0, etc
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
        int cnt = 0;
        int mini=1e5;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0 && grid[i][j]<=distanceThreshold) cnt++;
                // cout<<grid[i][j]<<" ";
            }
            if(cnt<=mini){
                mini = cnt;
                ans = i;
            }
            cnt=0;
            // cout<<endl;
        }

        return ans;
    }
};