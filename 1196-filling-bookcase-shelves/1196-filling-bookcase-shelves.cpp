class Solution {
public:
    int n; 
    vector<vector<int>> dp;
    int solve(int i, int remainW, vector<vector<int>> &books, int maxW, int &shelfWidth){
        if(i>=n) return maxW;

        if(dp[i][remainW]!=-1) return dp[i][remainW];

        int take = INT_MAX;
        if(books[i][0]<=remainW){
            take = solve(i+1,remainW-books[i][0],books,max(maxW,books[i][1]),shelfWidth);
        }
        int notTake = maxW + solve(i+1,shelfWidth-books[i][0],books,books[i][1],shelfWidth);
        return dp[i][remainW] = min(take,notTake);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        //{thickness,height}
        dp.resize(n,vector<int>(shelfWidth+1,-1));
        int remainW = shelfWidth;
        return solve(0,remainW,books,0,shelfWidth);
    }
};
