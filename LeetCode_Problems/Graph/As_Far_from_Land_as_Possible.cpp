class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<vector<int>> q;
        int added = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    q.push({i,j});
                    added++;
                }
            }
        }
        
        if(added == grid.size() * grid[0].size()) return -1;
        if(added == 0) return -1;
        
        int count = 0;
        while(!q.empty()) {
            
            count++;
            int layer_size = q.size();
            
            for(int i=0; i<layer_size; i++) {
                int cr = q.front()[0];
                int cc = q.front()[1];
                q.pop();

                if(cr - 1 >= 0 && grid[cr-1][cc] == 0) {
                    grid[cr-1][cc] = 1;
                    q.push( {cr-1,cc} );
                    added++;
                }
                if(cr + 1 < grid.size() && grid[cr+1][cc] == 0) {
                    grid[cr+1][cc] = 1;
                    q.push( {cr+1,cc} );
                    added++;
                }
                if(cc - 1 >= 0 && grid[cr][cc-1] == 0) {
                    grid[cr][cc-1] = 1;
                    q.push( {cr,cc-1} );
                    added++;
                }
                if(cc + 1 < grid[0].size() && grid[cr][cc+1] == 0) {
                    grid[cr][cc+1] = 1;
                    q.push( {cr,cc+1} );
                    added++;
                }
                
            }
            
            if(added >= grid.size() * grid[0].size()) break;

        }
        
        return count;
        
    }
};
