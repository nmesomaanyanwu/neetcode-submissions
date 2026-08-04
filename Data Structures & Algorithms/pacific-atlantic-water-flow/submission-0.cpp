class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        /* firstly i will try a dfs search solution
        1) i will make pacific grid and also a atlantic grid and set verything to zero 
        2) for every first and last colum we recurse and check if we can get water to flow into it from its neighbouring cell if we can then we set that on e as the next thing to recurse and set its update to true 
        3) we also do this for the colums 
        4) at the end we check if it was possible for water to both the pacific and atlantc grids and return
        */
        vector<vector<int>> ans;
        int rows = heights.size();
        int cols = heights[0].size();

        //grid - top - left
        vector<vector<bool>> pacific(rows , vector<bool>(cols , false));
        // grid - right bottom
        vector<vector<bool>> atlantic(rows , vector<bool>(cols , false));

        // recurse for every border element in both top and bottom cells
        for (int c = 0 ; c < cols ; c++){
            // for pacific 
            dfs(heights, 0 , c , pacific);
            // for atlantic
            dfs(heights, rows - 1 , c , atlantic);
        }
        
        // recurse for every border left and right 
        for (int r = 0 ; r < rows ; r++){
            // for pacific 
            dfs(heights, r , 0 , pacific);

            // for atlantic
            dfs(heights, r, cols -1 , atlantic);
        }

        for (int i = 0 ; i < rows; i++){
            for (int j = 0 ; j < cols; j++){
                if (atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }

private:
    void dfs(vector<vector<int>>& heights, int row , int col , vector<vector<bool>>& grid){
        int rows = heights.size();
        int cols = heights[0].size();
        vector<pair<int , int>> moves ={{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        grid[row][col] = true;

        for (auto [v, h] : moves){
            int nr = row + v;
            int nc = col + h;

            if (nr < 0 || nc < 0 || nr >=rows || nc >=cols){
                continue;
            }
            if (grid[nr][nc]){
                continue;
            }
            // we check if neighbour is greater
            if (heights[nr][nc] >= heights[row][col]){
                dfs(heights , nr , nc , grid);
            }

        }

    }
};
