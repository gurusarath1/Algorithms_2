class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        // Check for valid entrance
        if(maze[entrance[0]][entrance[1]] != '.') return -1;
        
        // Add all exists + entrance
        set<vector<long>> exits;
        for(int i=0; i<maze.size(); i++) {
            if(maze[i][0] == '.') exits.insert( {i, 0} );
            if(maze[i][maze[0].size() - 1] == '.') exits.insert( {i, (long)maze[0].size() - 1} );
        }
        
        for(int i=0; i<maze[0].size(); i++) {
            if(maze[0][i] == '.') exits.insert( {0, i} );
            if(maze[maze.size() - 1][i] == '.') exits.insert( {(long)maze.size() - 1, i} );
        }
        
        // Remove the entrace from the set of exists
        vector<long> ent_long;
        ent_long.push_back(entrance[0]);
        ent_long.push_back(entrance[1]);
        exits.erase(ent_long);
        
        // Check if no exit exists
        if(exits.size() == 0) return -1;
        
        // Start from entrance
        queue<vector<long>> q;
        q.push(ent_long);
        maze[entrance[0]][entrance[1]] = '+';
        
        
        int len = 0;
        while(!q.empty()) {
            int layer_size = q.size();
            
            for(int i=0; i<layer_size; i++) {
                vector<long> current_tile = q.front();
                q.pop();
                
                long cr = current_tile[0];
                long cc = current_tile[1];
                
                if(exits.find(current_tile) != exits.end()) return len;
                
                if(cr - 1 >= 0 && maze[cr-1][cc] == '.') {
                    maze[cr-1][cc] = '+';
                    q.push( {cr-1,cc} );
                }
                
                if(cr + 1 < maze.size() && maze[cr+1][cc] == '.') {
                    maze[cr+1][cc] = '+';
                    q.push( {cr+1,cc} );
                }
                
                if(cc - 1 >= 0 && maze[cr][cc-1] == '.') {
                    maze[cr][cc-1] = '+';
                    q.push( {cr,cc-1} );
                }
                
                if(cc + 1 < maze[0].size() && maze[cr][cc+1] == '.') {
                    maze[cr][cc+1] = '+';
                    q.push( {cr,cc+1} );
                }
            }
            
            len++;
        }
        
        return -1;
        
    }
};
