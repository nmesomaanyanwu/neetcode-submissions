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
            for (int c = 0; c < cols ; c++){
                if (board[r][c] == 'O'){
                    pos.push({r,c});
                }
            }
        }

        while (!pos.empty()){
            // check if its not a border element
            auto [r, c] = pos.front();
            pos.pop();
            if (r == 0 || c == 0 || r == rows-1 || c == cols -1){
                continue;
            }
            
            board[r][c] = 'X';
            for (auto [v , h] : moves){
                int nr = r + v;
                int nc = c + h;

                if (board[nr][nc] == 'X'){
                    continue;
                }

                pos.push({nr,nc});
            }

        }


        

        
        
    }
};
