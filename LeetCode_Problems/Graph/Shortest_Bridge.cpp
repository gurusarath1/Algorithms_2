class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        //Find Island 1
        queue<vector<int>> q;
        set<vector<int>> added_to_q;
        bool island_1_found = false;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    q.push( {i,j} );
                    added_to_q.insert({i,j});
                    grid[i][j] = -1;
                    
                    dfs_collect_one_island_tiles(grid, i, j, q, added_to_q);
                    island_1_found = true;
                    break;
                }
            }
            
            if(island_1_found) break;
        }
        
        // Go to Island 2 layer by layer
        int len = 0;
        while(!q.empty()) {
            int layer_size = q.size();
            
            for(int i=0; i<layer_size; i++) {
                vector<int> current_tile = q.front();
                q.pop();
                int cr = current_tile[0];
                int cc = current_tile[1];
                
                if(grid[cr][cc] == 1) return len - 1;
                
                
                if(cr-1 >= 0 && added_to_q.find({cr-1,cc}) == added_to_q.end() ) {
                    added_to_q.insert({cr-1,cc});
                    q.push( {cr-1,cc} );
                }
                
                if(cr+1 < grid.size() && added_to_q.find({cr+1,cc}) == added_to_q.end()) {
                    added_to_q.insert({cr+1,cc});
                    q.push( {cr+1,cc} );
                }
                
                if(cc-1 >= 0  && added_to_q.find({cr,cc-1}) == added_to_q.end()) {
                    added_to_q.insert({cr,cc-1});
                    q.push( {cr,cc-1} );
                }
                
                if(cc+1 < grid[0].size() && added_to_q.find({cr,cc+1}) == added_to_q.end()) {
                    added_to_q.insert({cr,cc+1});
                    q.push( {cr,cc+1} );
                }
                
            }
            
            len++;
        }
        
        return -1;
        
    }
    
    void dfs_collect_one_island_tiles(vector<vector<int>>& grid, int cr, int cc, queue<vector<int>> &q, set<vector<int>> &added_to_q) {
        
        if(cr-1 >= 0 && added_to_q.find({cr-1,cc}) == added_to_q.end() && grid[cr-1][cc] == 1) {
            added_to_q.insert({cr-1,cc});
            q.push( {cr-1,cc} );
            grid[cr-1][cc] = -1;
            dfs_collect_one_island_tiles(grid, cr-1, cc, q, added_to_q);
        }

        if(cr+1 < grid.size() && added_to_q.find({cr+1,cc}) == added_to_q.end() && grid[cr+1][cc] == 1) {
            added_to_q.insert({cr+1,cc});
            q.push( {cr+1,cc} );
            grid[cr+1][cc] = -1;
            dfs_collect_one_island_tiles(grid, cr+1, cc, q, added_to_q);
        }

        if(cc-1 >= 0  && added_to_q.find({cr,cc-1}) == added_to_q.end() && grid[cr][cc-1] == 1) {
            added_to_q.insert({cr,cc-1});
            q.push( {cr,cc-1} );
            grid[cr][cc-1] = -1;
            dfs_collect_one_island_tiles(grid, cr, cc-1, q, added_to_q);
        }

        if(cc+1 < grid[0].size() && added_to_q.find({cr,cc+1}) == added_to_q.end() && grid[cr][cc+1] == 1) {
            added_to_q.insert({cr,cc+1});
            q.push( {cr,cc+1} );
            grid[cr][cc+1] = -1;
            dfs_collect_one_island_tiles(grid, cr, cc+1, q, added_to_q);
        }

    }
};
