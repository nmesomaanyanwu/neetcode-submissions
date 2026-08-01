class Solution {
public:
int maxCount = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        

            for (int r = 0 ; r < grid.size(); r++){
                for (int c = 0 ; c < grid[0].size(); c++){

                    if (grid[r][c] == 1){
                        dfs(grid , r, c , 1);
                    }
                }
            }

            return maxCount;
        
    }
private:
     void dfs(vector<vector<int>>& grid , int row , int col , int count){
        // check if invalid 
        if (row >= grid.size() || row < 0  || col < 0 || col >= grid[0].size() || grid[row][col] != 1){
            return;
        }

        grid[row][col] = 0;
        maxCount = max(maxCount , count);

        dfs(grid , row + 1 , col , count++);
        dfs(grid , row - 1 , col , count++);
        dfs(grid , row , col + 1, count++);
        dfs(grid , row, col - 1  , count++);

     }
};
