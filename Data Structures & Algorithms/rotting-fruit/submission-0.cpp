class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*okay we do multi-source bfs , so:
        1) if put all the rotten stuff in a  a queue since thats what were starting with  
        2) we do level order for each cell and also check if its already been modified 
          
        */
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0 ; // will count all the level orders we have
        vector<vector<bool>> check(rows,vector<bool>(cols, false));
        queue<pair<int, int>> cells;

        for (int r = 0 ; r < rows ; r++){
            for (int c = 0 ; c < cols ; c++){
                if (grid[r][c] == 2){
                    cells.push({r , c});
                }
            }
        }
        vector<pair<int,int>> moves = {{1,0}, {-1,0}, {0,1}, {0, -1}};
        while (!cells.empty()){
                int level = cells.size();
                count++;

                for (int i = 0 ; i < level ; i++){
                    auto [r , c] = cells.front();
                    cells.pop();
                    check[r][c] = true;

                    for (auto [v, h] : moves){
                        int nr = r + v;
                        int nc = c + h; 

                        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || check[nr][nc]== true ){
                            continue; 
                        }

                        if (grid[nr][nc] == 1){
                            cells.push({nr , nc});
                        }
                    }
                }
        }
        if (count - 1 == 0){
            return -1;
        }
        return count - 1;
    }
};
