#define ll long long
class Solution {
public:
    int n,m;
    // vector<vector<ll> dp;
    // int dx[] = {-1,-1,-1,0,0,1,1,1};
    // int dy[] = {-1,0,1,-1,1,-1,0,1};

    // bool check(int i, int j){
    //     return i>=0 && i<n && j>=0 && j<m;
    // }

    // ll solve(int i, int j, vector<vector<int>> &points){
    //     if(!check(i,j)) return 0;

    //     if(dp[i][j]!=-1) return dp[i][j];


    // }

    long long maxPoints(vector<vector<int>>& points) {
        n = points.size();
        m = points[0].size();

        vector<ll> prev(m);
        for(int i=0;i<m;i++) prev[i] = points[0][i];

        for(int i=1;i<n;i++){
            vector<ll> left(m,0);
            vector<ll> right(m,0);

            left[0] = prev[0];
            for(int j=1;j<m;j++){
                left[j] = max(left[j-1]-1,prev[j]);
            }
            right[m-1] = prev[m-1];
            for(int j=m-2;j>=0;j--){
                right[j] = max(right[j+1]-1,prev[j]);
            }

            vector<ll> curr(m);
            for(int j=0;j<m;j++){
                curr[j] = points[i][j] + max(left[j],right[j]);
            }
            prev = curr;
        }

        return *max_element(prev.begin(),prev.end());
    }
};