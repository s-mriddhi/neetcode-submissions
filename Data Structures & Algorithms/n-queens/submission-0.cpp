class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        backtrack(0, board); // Going row wise 
        return res;
    }
    void backtrack(int r, vector<string> &board){
        int n = board.size();
        if(r==board.size()){
            res.push_back(board);
            return;
        }
        // check every col possibility on that row
        for(int c = 0; c<n; c++){
            if(isSafe(r,c,board))
           {
             board[r][c]='Q';
             backtrack(r+1, board);
             board[r][c] = '.';
           }
        }
    }

    bool isSafe(int r, int c, vector<string> &board){
        // check any vertical 
        int n = board.size();
        for(int i = r-1; i>=0; i--){
            if(board[i][c]=='Q') return false;
        }
        // Check left upper diagonal
        for(int i = r-1, j = c-1; i>=0 && j>=0; i--,j--){
            if(board[i][j]=='Q') return false;
        }
        // Check right upper diagonal
        for(int i = r-1, j = c+1; i>=0 && j<n; i--,j++){
            if(board[i][j]=='Q') return false;
        }

        return true;
    }
};
