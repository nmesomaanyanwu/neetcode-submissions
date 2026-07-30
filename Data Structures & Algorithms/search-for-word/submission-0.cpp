class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        /*
        main loop : we iterate over every single letter because it could start from anywhere
        1)if bactrack return true in once instance instantky return true\
        else , if we wait till the end and backtrack hasnt done anything return false 

        for the backtracking 
        we can either move up , down left or right 
        when do we return if the word is fount 
        what is a valid move to check either up , down left , right
        whats an invalid move if its out of bounds 

        */
        int n= board.size();
        int z = board[0].size();
        for(int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < z ; j++){
                if (dfs(board , word , i , j , 0) ){
                    return true;
                }
            } 
        } 
        
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string word, int vertical  , int horizontal , int index) {
        if (index == word.size()){
            return true; 
        }

        if (vertical < 0 || horizontal >=board[0].size() || horizontal < 0 || vertical >= board.size()){
            return false; 
        }

        if (board[vertical][horizontal] != word[index]){
            return false; 
        }

        char n = board[vertical][horizontal];
        board[vertical][horizontal] = '#';

        bool found = 
        dfs(board , word,vertical + 1, horizontal ,  index+ 1) ||        dfs(board , word,vertical - 1, horizontal ,  index+ 1) ||        dfs(board , word,vertical, horizontal + 1 ,  index+ 1) ||        dfs(board , word,vertical, horizontal - 1 ,  index+1);

        board[vertical][horizontal] = n;

        return found;
        
        
    }

};
