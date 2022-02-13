class Solution {
public:
    
    #define EMPTY 0
    #define FRESH 1
    #define ROTTEN 2
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<vector<int>> q;
        set<vector<int>> rotten_oranges;
        
        int num_fresh_oranges = 0;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == ROTTEN) {
                    q.push({i,j});
                    rotten_oranges.insert({i,j});
                } else if(grid[i][j] == FRESH) {
                    num_fresh_oranges += 1;
                }
            }
        }
        
        
        
        vector<vector<int>> next_vecs = { {0,1}, {1,0}, {-1,0}, {0,-1} };
        
        // Multisource BFS
        int current_time = 0;
        while(!q.empty() && num_fresh_oranges > 0) {
            
            int num_oranges_rotten_at_current_time = q.size();
            
            for(int i=0; i<num_oranges_rotten_at_current_time; i++) {
                
                vector<int> current_rotten_orange = q.front();
                q.pop();
                
                for(vector<int> vec : next_vecs) {
                    vector<int> next_rot_orange(2);
                    
                    next_rot_orange[0] = current_rotten_orange[0] + vec[0];
                    next_rot_orange[1] = current_rotten_orange[1] + vec[1];
                    
                    // Check grid boundry
                    if(next_rot_orange[0] < 0 || next_rot_orange[1] < 0 || next_rot_orange[0] >= grid.size() || next_rot_orange[1] >= grid[0].size()) continue;
                    
                    // Make sure the next orange is not rotten and the space is not empty
                    if(grid[next_rot_orange[0]][next_rot_orange[1]] != EMPTY && rotten_oranges.find(next_rot_orange) == rotten_oranges.end()) {
                        rotten_oranges.insert(next_rot_orange);
                        q.push(next_rot_orange);
                        num_fresh_oranges--;
                    }
                    
                }
                
                // If all oranges are rotten not need to continue with the bfs
                if(num_fresh_oranges == 0) break;
            }
            
            current_time++;
        }
        
        // if All oranges did not rot
        if(num_fresh_oranges > 0) return -1;
        
        return current_time;
    }
};
