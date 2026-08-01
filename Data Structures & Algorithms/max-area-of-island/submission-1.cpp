class Solution {
public:
int maxCount = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        

            for (int r = 0 ; r < grid.size(); r++){
                for (int c = 0 ; c < grid[0].size(); c++){

                    if (grid[r][c] == 1){
                        int count = bfs(grid , r, c, 0);
                        maxCount = max(count , maxCount);
                    }
                }
            }

            return maxCount;
        
    }
private:
     int bfs(vector<vector<int>>& grid , int row , int col , int count){
        
        queue<pair<int,int>> pos;
        vector<pair<int, int>> moves = {{1,0}, {-1,0}, {0, 1}, {0, -1}};
        pos.push({row , col}); // the first position is in our queue 
        grid[row][col] = 0; 
        count++; 

        while(!pos.empty()){
            auto [r , c] = pos.front();
            pos.pop();

            for(auto [v , h] : moves){
                int nr = r+v;
                int nc = c+ h;
                if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1){
                    pos.push({nr,nc});
                    grid[nr][nc] = 0;
                    count++;
                }
            }

        }
        
        return count;
     }
};
