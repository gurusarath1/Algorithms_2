class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        set<pair<int,int>> visited;
        int len,max_len = 0;
        map<pair<int,int>, int> memo;
        
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                len = traverse(matrix, i, j, visited, memo);
                max_len = max(max_len, len);
            }
        }
        
        return max_len;
    }
    
    int max_len = 0;
    
    int traverse(vector<vector<int>>& matrix, int i, int j, set<pair<int,int>> &visited, map<pair<int,int>, int> &memo) {
        
        vector<vector<int>> vecs = {{-1,0},{1,0},{0,-1},{0,1}};
        pair<int,int> current_tile = {i,j};
        
        if(memo.find(current_tile) != memo.end()) {
            return memo[current_tile];
        }
        
        int max_len = 0, len = 0;
        bool end_of_trail = true;
        
        visited.insert(pair<int,int>{i,j});
        
        for(vector<int> vec : vecs) {
            
            if(i+vec[0] >=0 && i+vec[0] < matrix.size()) { // Check row bounds
                if(j+vec[1] >=0 && j+vec[1] < matrix[0].size()) { // Check col bounds
                    if( visited.end() == visited.find( pair<int,int>{i+vec[0] , j+vec[1]} ) ) { // Check if already visited
                        if(matrix[i+vec[0]][j+vec[1]] > matrix[i][j]) { // Check if increasing
                            end_of_trail = false;
                            len = traverse(matrix, i+vec[0], j+vec[1], visited, memo);
                            max_len = max(max_len, len+1);
                        }
                    }
                }
            }
            
        }
        
        visited.erase(current_tile);
        
        if(!end_of_trail) {
            memo[current_tile] = max_len;
            return max_len;
        }
        
        memo[current_tile] = 1;
        return 1;
        
    }
    
    
};
