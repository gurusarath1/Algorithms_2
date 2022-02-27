class Solution {
public:
  
  // TIME LIMIT EXCEEDED
    
    map< vector<int> , int > best_efforts; 
    
    set< vector<int> > visited;
    
    vector<int> destination_tile;
    
    int global_best = INT_MAX;
    
    vector<vector<int>> next_steps(int max_rows, int max_cols, int current_i, int current_j) {
        
        vector<vector<int>> vecs = { {0,1}, {1,0}, {-1,0}, {0,-1} };
        vector<vector<int>> next_tiles;
        
        for(vector<int> vec : vecs) {
            int next_i = vec[0] + current_i;
            int next_j = vec[1] + current_j;
            
            if(next_i < 0 || next_i >= max_rows) continue;
            if(next_j < 0 || next_j >= max_cols) continue;
            
            next_tiles.push_back( {next_i, next_j} );
            
        }
        
        return next_tiles;
    }
    
    
    
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        destination_tile.push_back(heights.size() - 1);
        destination_tile.push_back(heights[0].size() - 1);
        
        return minEffortSupport({0,0}, 0, heights);
        
    }
    
    int minEffortSupport(vector<int> current_tile, int current_max_effort, vector<vector<int>> &heights) {
        
        if(current_tile == destination_tile) {
            return current_max_effort;
        }
        
        visited.insert(current_tile);
        
        vector<vector<int>> next_tiles = next_steps(heights.size(), heights[0].size(), current_tile[0], current_tile[1]);
        int best_effort_from_here = INT_MAX;
        for(vector<int> next_tile : next_tiles) {
            
            if(visited.find(next_tile) == visited.end()) {
                int effort_to_go_to_next = abs(heights[next_tile[0]][next_tile[1]] - heights[current_tile[0]][current_tile[1]]);
                
                if(effort_to_go_to_next > global_best) continue;
                
                int effort_from_here = minEffortSupport(next_tile, effort_to_go_to_next > current_max_effort ? effort_to_go_to_next : current_max_effort, heights);
                
                if(effort_from_here < best_effort_from_here) {
                    best_effort_from_here = effort_from_here;
                }
            }
            
        }
        
        visited.erase(current_tile);
        
        if(global_best > best_effort_from_here) {
            global_best = best_effort_from_here;
        }
        
        return best_effort_from_here;
        
    }
    
    
};
