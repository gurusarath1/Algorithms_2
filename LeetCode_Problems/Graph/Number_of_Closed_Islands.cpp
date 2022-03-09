class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        // Crear all the land that is at the edges
        for(int i=0; i<grid.size(); i++) {
            if(grid[i][0] == 0) dfs(grid, i, 0);
            if(grid[i][grid[0].size()-1] == 0) dfs(grid, i, grid[0].size()-1);
        }
        for(int i=0; i<grid[0].size(); i++) {
            if(grid[0][i] == 0) dfs(grid, 0, i);
            if(grid[grid.size()-1][i] == 0) dfs(grid, grid.size()-1,i);
        }
        
        // Count number of island
        int count = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<int>> &grid, int i, int j) {
        grid[i][j] = 1;
        
        if(i-1 >= 0 && grid[i-1][j] == 0) dfs(grid, i-1, j);
        if(i+1 < grid.size() && grid[i+1][j] == 0) dfs(grid, i+1, j);
        if(j-1 >= 0 && grid[i][j-1] == 0) dfs(grid, i, j-1);
        if(j+1 < grid[0].size() && grid[i][j+1] == 0) dfs(grid, i, j+1);
    }
};
