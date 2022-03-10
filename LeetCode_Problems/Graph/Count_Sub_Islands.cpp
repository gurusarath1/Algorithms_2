class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int count = 0;
        
        for(int i=0; i<grid2.size(); i++) {
            for(int j=0; j<grid2[0].size(); j++) {
                if(grid2[i][j] == 1) {
                    int is_subland = 1;
                    dfs_grid2(grid1, grid2, i, j, is_subland);
                    if(is_subland) count++;
                }
            }
        }
        
        return count;
        
    }
    
    void dfs_grid2(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int cr, int cc, int &is_subland) {
        
        if(grid1[cr][cc] != grid2[cr][cc]) {
            is_subland = 0;
            return;
        }
        
        grid2[cr][cc] = 0;
        
        if(cr - 1 >= 0 && grid2[cr-1][cc] == 1) dfs_grid2(grid1, grid2, cr-1, cc, is_subland);
        if(cr + 1 < grid2.size() && grid2[cr+1][cc] == 1) dfs_grid2(grid1, grid2, cr+1, cc, is_subland);
        if(cc - 1 >= 0 && grid2[cr][cc-1] == 1) dfs_grid2(grid1, grid2, cr, cc-1, is_subland);
        if(cc + 1 < grid2[0].size() && grid2[cr][cc+1] == 1) dfs_grid2(grid1, grid2, cr, cc+1, is_subland);
        
    } 
};
