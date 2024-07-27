#define pb push_back
//Explanation: queen can go in all the 8 directions, we'll be filling from left to right, so we'll need to check only UPPER LEFT DIAGONAL, LOWER LEFT DIAGONAL, LEFT. Will be done using isSafe function
// Then use backtracking in solve function 

class Solution {
public:
    vector<vector<string>> ans; //collection of all answers
    
    bool isSafe(int i, int j, vector<string> board, int n){
        int row = i;
        int col = j;
        //check upper left diagonal
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        //check left
        row = i;col = j;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        //check lower left diagonal
        row = i;col = j;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            col--;
            row++;
        }
        return true;
    }

    void solve(int i, int j, vector<string> &board, int n){
        if(j==n){ //reached end so got an ans
            ans.pb(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(isSafe(i,j,board,n)){
                board[i][j]='Q';
                solve(i,j+1,board,n); 
                board[i][j]='.'; //backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> board(n,s); //[".Q..","...Q","Q...","..Q."]
        solve(0,0,board,n);
        return ans;
    }
};