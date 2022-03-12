class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        vector<vector<bool>> visited_grid(grid.size(), vector<bool>(grid[0].size(), false) );
        queue<vector<int>> q;
        
        if(grid[0][0] == 1) return -1;
        
        q.push( {0,0} );
        visited_grid[0][0] = true;
        
        int num_rows = grid.size() - 1;
        int num_cols = grid[0].size() - 1;
        
        vector<int> goal_tile = {num_rows, num_cols};
        vector<vector<int>> vecs = { {1,0},{-1,0},{0,1},{0,-1},{-1,1},{1,-1},{1,1},{-1,-1} };
        
        int len = 0;
        while(!q.empty()) {
            int layer_size = q.size();
            len++;
            
            for(int i=0; i<layer_size; i++) {
                vector<int> current_tile = q.front();
                q.pop();
                
                int cr = current_tile[0];
                int cc = current_tile[1];
                
                if(current_tile == goal_tile) {
                    return len;
                }
                
                for(vector<int> vec : vecs) {
                    int next_r = vec[0] + cr;
                    int next_c = vec[1] + cc;
                    if(next_r >= 0 && next_c >= 0 && next_r < grid.size() && next_c < grid[0].size()) {
                        if(!visited_grid[next_r][next_c] && grid[next_r][next_c] == 0) {
                            q.push( {next_r, next_c} );
                            visited_grid[next_r][next_c] = true;
                        }   
                    }
                }
            }
            
            
        }
        
        return -1;
    }
};
