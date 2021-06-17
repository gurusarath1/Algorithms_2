class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<bool>> visited_grid(grid.size(), vector<bool>(grid[0].size(), false));
        int components = 0;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(!visited_grid[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, visited_grid);
                    components += 1;
                }
            }
        }
        
        return components;
        
    }
    
    
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &visited_grid) {
        visited_grid[i][j] = true;
        
        if(i+1 < grid.size() && grid[i+1][j] == '1'&& !visited_grid[i+1][j]) {
            dfs(i+1, j, grid, visited_grid);
        }
        
        if(i-1 >= 0 && grid[i-1][j] == '1'&& !visited_grid[i-1][j]) {
            dfs(i-1, j, grid, visited_grid);
        }

        if(j+1 < grid[0].size() && grid[i][j+1] == '1' && !visited_grid[i][j+1]) {
            dfs(i, j+1, grid, visited_grid);
        }
        
        if(j-1 >= 0 && grid[i][j-1] == '1' && !visited_grid[i][j-1]) {
            dfs(i, j-1, grid, visited_grid);
        }
        
    }
    
};
