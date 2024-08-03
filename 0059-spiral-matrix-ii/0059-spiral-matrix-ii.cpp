class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int cnt = 1;

        int l=0,r=n-1,u=0,d=n-1;

        bool right = true;
        bool down = true;
        while(l<=r && u<=d){
            if(right){
                for(int i=l;i<=r;i++){ //l->r
                    ans[u][i] = cnt;
                    cnt++;
                }
                u++;
                right = !right;
            }else{
                for(int i=r;i>=l;i--){ //r->l
                    ans[d][i] = cnt;
                    cnt++;
                }
                d--;
                right = !right;
            }

            if(down){
                for(int i=u;i<=d;i++){ //u->d
                    ans[i][r] = cnt;
                    cnt++;
                }
                r--;
                down = !down;
            }else{
                for(int i=d;i>=u;i--){ //d->u
                    ans[i][l] = cnt;
                    cnt++;
                }
                l++;
                down = !down;
            }
        }

        return ans;
    }
};