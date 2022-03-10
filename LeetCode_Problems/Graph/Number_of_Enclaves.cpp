class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        for(int i=0; i<grid.size(); i++) {
            if(grid[i][0] == 1) dfs(grid, i, 0);
            if(grid[i][grid[0].size() - 1] == 1) dfs(grid, i, grid[0].size() - 1);
        }

        for(int i=0; i<grid[0].size(); i++) {
            if(grid[0][i] == 1) dfs(grid, 0, i);
            if(grid[grid.size() - 1][i] == 1) dfs(grid, grid.size() - 1, i);
        }
        
        int count =0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]) count++;
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<int>> &grid, int cr, int cc) {
        
        grid[cr][cc] = 0;
        
        if(cr - 1 >= 0 && grid[cr-1][cc] == 1) dfs(grid,cr-1,cc);
        if(cr + 1 < grid.size() && grid[cr+1][cc] == 1) dfs(grid,cr+1,cc);
        if(cc - 1 >= 0 && grid[cr][cc-1] == 1) dfs(grid,cr,cc-1);
        if(cc + 1 < grid[0].size() && grid[cr][cc+1] == 1) dfs(grid,cr,cc+1);
        
    }
};
