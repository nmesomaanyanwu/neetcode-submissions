class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> cells; // we will keep all the treasure chest cells first
    
        for (int r = 0 ; r < rows; r++){
            for (int c = 0 ; c < cols ; c++){
                if (grid[r][c] == 0){
                    cells.push({r, c});
                }
            }
        }

        // so we put all the cell where its 0  now lets define moves that can be done 
        vector<pair<int, int>> moves = {{1,0}, {-1 ,0}, {0, 1}, {0, -1}};

        while(!cells.empty()){
            auto [row , col] = cells.front();
            cells.pop();

            for (auto [v , h]: moves){
                // make new moves
                int nr = row + v;
                int nc = col + h;

                if ( nr < 0 || nr >= rows || nc < 0 || nc >= cols ||grid[nr][nc] != INT_MAX){
                    continue;
                }

                
                grid[nr][nc] = grid[row][col] + 1;
                cells.push({nr,nc});

            }
        }
        
    }

   
};
