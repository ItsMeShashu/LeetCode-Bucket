class Solution {
public:
    //Checking the elements of the previous rows........ 
    bool isValid(vector<string> &board, int row, int col){
        // check col elements  of prev. rows
        for(int i=row; i>=0; i--)
            if(board[i][col] == 'Q') return false;

        // check left diagonal elements of prev. rows
        for(int i=row,j=col; i>=0 && j>=0; i--,j--)
            if(board[i][j] == 'Q') return false;

        //check right diagonal elements of prev. rows
        for(int i=row,j=col; i>=0 && j<board.size(); i--,j++)
            if(board[i][j] == 'Q') return false;

        return true;
    }

    void func(vector<string> &board, int row, vector<vector<string>>& ans, int n){
        if(row == n){
            ans.push_back(board);
            return; 
        }
        // iterate every possible position
        for(int col=0; col<n; col++){
            if(isValid(board, row, col)){
                board[row][col] = 'Q' ;

                func(board, row+1, ans, n); 

                board[row][col] = '.' ;
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans ; 
        if(n<=0) return ans;
        int row = 0;
        vector<string> board(n,  string(n, '.')) ;
        func(board, row, ans, n); 

        return ans ;
    }
};