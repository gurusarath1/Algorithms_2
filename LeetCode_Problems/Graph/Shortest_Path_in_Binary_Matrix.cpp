class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        vector<vector<int>> vecs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        queue<vector<int>> q;
        set<vector<int>> visited;
        
        if(grid[0][0] == 1) return -1;
        
        q.push(vector<int>{0,0});
        visited.insert(vector<int>{0,0});
        int level = 0;
        while(!q.empty()) {
            
            int level_len = q.size();
            
            vector<int> current_node;
            level++;
            for(int i=0 ; i<level_len; i++) {
                current_node = q.front();
                q.pop();
                
                if(current_node[0] == grid.size() - 1 && current_node[1] == grid[0].size() - 1) {
                    return level;
                }

                for(vector<int> vec : vecs) {
                    
                    vector<int> possible_next = { current_node[0] + vec[0] , current_node[1] + vec[1] };

                    if(possible_next[0] >= 0 && possible_next[1] >= 0) {
                        if(possible_next[0] < grid.size() && possible_next[1] < grid[0].size()) {
                            if( grid[possible_next[0]][possible_next[1]] == 0) {
                                if(visited.find(possible_next) == visited.end()) {
                                    visited.insert(possible_next);
                                    q.push(possible_next);
                                }
                            }
                        }
                    }
                    
                }
            }
            
        }
        
        return -1;
    }
};
