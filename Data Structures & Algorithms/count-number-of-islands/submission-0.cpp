class Solution {
    int count = 0 ;
public:
    int numIslands(vector<vector<char>>& grid) {
        /*for every node start we need need to check if can fnd a pathway 
        1) we make a for loop to have a start index for each row column we can do bfs ;
        2) when does the bfs we have a queue abd we add all the connections that that has then for then we explore the. rest when were done we return our 
        3) we add what we exploew to our set we use the deque to do the bfs anbs then we add to vector 
        */

        for (int i = 0 ; i < grid.size(); i++){
            for (int j = 0 ; j < grid[0].size(); j++ ){
                if (grid[i][j]== '1'){
                    bfs(grid, i , j);
                    count++;
                    
                }
            }
        }
        return count;
    }
private:
    void bfs(vector<vector<char>>& grid , int r , int c){
        /*We neeed this bfs to return the island */
        deque<pair<int , int>> islands; 
        islands.push_back({r, c});
        grid[r][c] = '0';

        while (!islands.empty()){
            
            auto [row , col] = islands.back();
            islands.pop_back();
           
             // check each direction and append 
             if ((col!=grid[0].size()-1) && grid[row][col + 1] == '1'){
                    islands.push_back({row , col + 1});
                    grid[row][col + 1] = '0';
            }
            if ((col!=0) && grid[row][col -1] == '1'){
                    islands.push_back({row , col - 1});
                    grid[row][col - 1] = '0';
            }
            if ((row!=grid.size()-1) && grid[row + 1][col] == '1'){
                    islands.push_back({row + 1 , col});
                    grid[row + 1][col] = '0';
                }
            if ((row!=0) && grid[row - 1][col] == '1'){
                    islands.push_back({row - 1, col});
                    grid[row - 1][col] = '0';
             }
            
        }
      


    } 
};
