class Solution {
public:
    int n; 
    vector<vector<int>> dp; //{index,remainingWeight in shelf}
    int solve(int i, int remainW, vector<vector<int>> &books, int maxW, int &shelfWidth){
        if(i>=n) return maxW;

        if(dp[i][remainW]!=-1) return dp[i][remainW];

        int sameShelf = INT_MAX;
        if(books[i][0] <= remainW){ //place in same layer of shelf
            sameShelf = solve(i+1,remainW-books[i][0],books,max(maxW,books[i][1]),shelfWidth);
        }
        //when moving to new layer of shelf, add maxW from previous layer and proceed
        int newShelf = maxW + solve(i+1,shelfWidth-books[i][0],books,books[i][1],shelfWidth);

        //return minimum
        return dp[i][remainW] = min(sameShelf,newShelf);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        //books -> {thickness,height}
        dp.resize(n,vector<int>(shelfWidth+1,-1));
        int remainW = shelfWidth;
        return solve(0,remainW,books,0,shelfWidth);
    }
};
