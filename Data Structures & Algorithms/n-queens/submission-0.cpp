class Solution {
vector<vector<string>> ans;

public:
    vector<vector<string>> solveNQueens(int n) {
       vector<string> board(n , string(n , '.'));
        backtrack(0 , board , n);
        return ans; 

        
    }

private:
    void backtrack(int row , vector<string> board, int n) {
        if (row == n){
            ans.push_back(board);
            return;
        }

        for (int col = 0 ; col < n ; col++){
            if (!isValid(col , row , board, n)){
                continue;
            }

            board[row][col] = 'Q';
            backtrack(row + 1 , board , n);
            board[row][col] = '.';
            
          
        } 
    } 


    bool isValid(int col , int row,vector<string> board, int n){

        // check column above 
        for (int r = 0 ; r < row ; r++){
            if (board[r][col] == 'Q'){
                return false; 
            }
        }

        // check up left diagonal 
        for (int r = row - 1 , c = col - 1 ; c >= 0 && r>= 0 ; r -- ,c--){
            if (board[r][c] == 'Q'){
                return false;
            }
        }

        // check up right diagonal
         for (int r = row - 1 , c = col + 1 ; c <n  && r>= 0 ; r -- ,c++){
            if (board[r][c] == 'Q'){
                return false;
            }
        }

        return true;
        
    }
};
