class Solution {
public:
    void solve(vector<vector<char>>& board) {

        /*We will start from the o's and pop them into the queue
        - for each o we check if its a border edge if so we continue to the next in queue
        - for the nect in queue after we check its not a border element we do the moves if its neighbouring cell is 0 we add and we change that on to 0 
        */
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int,int>> pos;
        vector<pair<int,int>> moves = {{1,0},{-1,0},{0,1}, {0,-1}};

        for (int r = 0 ; r < rows ; r++){
            // we check if the position is a border , first and last column 
            if (board[r][0] == 'O'){
                pos.push({r,0});
                board[r][0] = '#';
            }
            if (board[r][cols - 1] == 'O'){
                pos.push({r , cols -1});
                board[r][cols - 1] = '#';
            }
            
        }
        // check the top and bottom rows 
        for (int c = 0 ; c < cols ; c++){
            // we check if the position is a border
            if (board[0][c] == 'O'){
                    pos.push({0,c});
                    board[0][c] = '#';
            }

            if (board[rows - 1][c] == 'O'){
                pos.push({rows - 1 , c});
                board[rows - 1][c] = '#';
            }
            
        }

        while (!pos.empty()){
            // check if its not a border element
            auto [r, c] = pos.front();
            pos.pop();
            
            for (auto [v , h] : moves){
                int nr = r + v;
                int nc = c + h;

                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols){
                    continue;
                }

                if (board[nr][nc] != 'O'){
                    continue;
                }
                board[nr][nc] = '#';
                pos.push({nr,nc});
            }
    }


        for (int i = 0 ; i < board.size(); i++){
            for (int j = 0 ; j < board[0].size(); j++){

                    if (board[i][j] == '#'){
                        board[i][j] = 'O';
                    }
                    else if (board[i][j] == 'O'){
                        board[i][j] = 'X';
                    }
                }
            }

    }
};
