class Solution {
public:
    bool check(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> v(n,vector<int>(m));
        int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int t = board[i][j];
                v[i][j]=t;
                int cnt = 0;
                for(int k=0;k<8;k++){
                    int nr = i+dx[k];
                    int nc = j+dy[k];

                    if(check(nr,nc,n,m)){
                        if(board[nr][nc]==1) cnt++;
                    }
                }
                if(t==1){
                    if(cnt<2) v[i][j]=0;
                    else if(cnt==2 || cnt==3) v[i][j]=1;
                    else if(cnt>3) v[i][j]=0;
                }else if(t==0){
                    if(cnt==3) v[i][j]=1;
                }
            }
        }

        board = v;
    }
};