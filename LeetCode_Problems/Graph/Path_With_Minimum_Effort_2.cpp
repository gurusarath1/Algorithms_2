static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
  
  /// SOME TIME TIME LIMIT EXCEEDS
    
    static bool compare(vector<int> a, vector<int> b) {
        return a[2] > b[2];
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int r = heights.size();
        int c = heights[0].size();
        
        vector<int> dest = {r-1, c-1};
        vector<vector<int>> distances(r, vector<int>(c,INT_MAX));
        distances[0][0] = 0; // Start tile is at 0 distance
        
        
        priority_queue<vector<int>, vector<vector<int>>, function<bool(vector<int>, vector<int>)>  > q(compare);
        vector<vector<bool>> visited(r, vector<bool>(c,false));
        q.push({0,0,0});
        
        while(!q.empty()) {
            
            vector<int> current_tile_with_dist = q.top();
            q.pop();
            
            vector<int> current_tile = {current_tile_with_dist[0], current_tile_with_dist[1]};
            
            //if(visited.find(current_tile) != visited.end()) {
            if(visited[current_tile[0]][current_tile[1]] == true) {
                continue;
            }
            
            if(current_tile == dest) {
                // Found the shortest path
                return current_tile_with_dist[2];
            }
            
            //visited.insert(current_tile);
            visited[current_tile[0]][current_tile[1]] = true;
            
            vector<vector<int>> next_tiles;
            if(current_tile[0] - 1 >= 0) {
                next_tiles.emplace_back(vector<int>{current_tile[0] - 1, current_tile[1]});
            }
            
            if(current_tile[1] - 1 >= 0) {
                next_tiles.emplace_back(vector<int>{current_tile[0], current_tile[1] - 1});
            }
            
            if(current_tile[0] + 1 <= r-1) {
                next_tiles.emplace_back(vector<int>{current_tile[0] + 1, current_tile[1]});
            }

            if(current_tile[1] + 1 <= c-1) {
                next_tiles.emplace_back(vector<int>{current_tile[0], current_tile[1] + 1});
            }
            
            for(vector<int> next_tile : next_tiles) {
                
                //if(visited.find(next_tile) == visited.end()) {
                if(visited[next_tile[0]][next_tile[1]] == false) {
                    int effort_to_go = heights[current_tile[0]][current_tile[1]] - heights[next_tile[0]][next_tile[1]];
                    effort_to_go = effort_to_go < 0 ? -effort_to_go : effort_to_go;
                    int path_effort = max(effort_to_go , distances[current_tile[0]][current_tile[1]]);

                    if(effort_to_go < distances[next_tile[0]][next_tile[1]]) {
                        distances[next_tile[0]][next_tile[1]] = path_effort;
                        next_tile.emplace_back(path_effort);
                        q.push(next_tile);
                    }
                }
                
            }
            
            
        }
        
        return -1;
        
    }
};
