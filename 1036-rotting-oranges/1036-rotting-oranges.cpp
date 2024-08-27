class Solution {
public:
    int n,m;

    // check func
    bool check(int i, int j){
        return i>=0 && i< n && j>=0 && j<m;
    }

    // direction vectors
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};

    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int t = 0; //time 
        int freshCnt=0;

        queue<pair<int,int>> q; //{i,j} -> rotten oranges
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j}); 
                }
                if(grid[i][j]==1) freshCnt++;
            }
        }

        int cnt = 0; //cnt the ornages that are being rotten
         
        while(!q.empty()){
            int size = q.size(); 
            bool ch = false;
            while(size--){
                auto top = q.front();
                q.pop();

                int r = top.first;
                int c = top.second;

                for(int k=0;k<4;k++){
                    int nr = r + dx[k];
                    int nc = c + dy[k];

                    if(check(nr,nc) && grid[nr][nc]==1){
                        q.push({nr,nc});
                        grid[nr][nc]=2;
                        cnt++;
                        ch = true;
                    }
                }
            }
            if(ch) t++;
        }

        if(cnt!=freshCnt) return -1;
        return t;
    }
};