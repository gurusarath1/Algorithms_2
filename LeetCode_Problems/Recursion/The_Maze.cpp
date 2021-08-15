class Solution {
public:
    
    vector<vector<int>> direction_vectors = { {0,-1},{0,1},{-1,0},{1,0} };
    set<vector<int>> visited;
    enum directions {LEFT, RIGHT, UP, DOWN};
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        
        return hasPath_support(maze, start, destination, LEFT) ||
            hasPath_support(maze, start, destination, RIGHT) || 
            hasPath_support(maze, start, destination, UP) ||
            hasPath_support(maze, start, destination, DOWN);
    }
    
    bool hasPath_support(vector<vector<int>>& maze, 
                         vector<int>& current_location, 
                         vector<int>& destination,
                         directions direction) {
        
        visited.insert(current_location);
        
        if(current_location == destination) return true;
        
        vector<int> direc_vec = direction_vectors[direction];
        
        vector<int> next_location = current_location;
        vector<int> prev_location = current_location;
        
        while(next_location[0] >= 0 && next_location[1] >= 0 && next_location[0] < maze.size() && next_location[1] < maze[0].size() && (maze[next_location[0]][next_location[1]] != 1))
        {
            prev_location = next_location;
            next_location[0] += direc_vec[0];
            next_location[1] += direc_vec[1];
        }
        
        next_location = prev_location;
        
        if(visited.find(next_location) == visited.end()) {
            
            if(hasPath_support(maze, next_location, destination, LEFT)) return true;
            if(hasPath_support(maze, next_location, destination, RIGHT)) return true;
            if(hasPath_support(maze, next_location, destination, UP)) return true;
            if(hasPath_support(maze, next_location, destination, DOWN)) return true;
            
        }

        return false;
        
    }
};
