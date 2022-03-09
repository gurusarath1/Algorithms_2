class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int max_area = 0;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    int area = dfs_area(grid, i, j);
                    if(area > max_area) max_area = area;
                }
            }
        }
        
        
        return max_area;
    }
    
    int dfs_area(vector<vector<int>>& grid, int cr_index, int cc_index) {
        
        grid[cr_index][cc_index] = 0;
        
        int area = 0;
        
        if(cr_index - 1 >= 0 && grid[cr_index - 1][cc_index]) area += dfs_area(grid, cr_index-1, cc_index);
        if(cr_index + 1 <= grid.size() - 1 && grid[cr_index + 1][cc_index]) area += dfs_area(grid, cr_index+1, cc_index);
        if(cc_index - 1 >= 0 && grid[cr_index][cc_index - 1]) area += dfs_area(grid, cr_index, cc_index-1);
        if(cc_index + 1 <= grid[0].size() - 1 && grid[cr_index][cc_index + 1]) area += dfs_area(grid, cr_index, cc_index+1);
        
        return area + 1;
    }
};
