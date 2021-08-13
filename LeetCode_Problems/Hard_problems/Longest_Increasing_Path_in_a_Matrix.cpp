class Solution {
public:
    
    int longest_path = 0;
    int max_row_index;
    int max_col_index;
    vector<vector<int>> next_vector = { vector<int>{1,0}, vector<int>{0,1}, vector<int>{0,-1}, vector<int>{-1,0} };
    map<pair<int,int>, int> memo;
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        max_row_index = matrix.size() - 1;
        max_col_index = matrix[0].size() - 1;
        
        set<pair<int,int>> visited_list;
        for(int i=0; i<=max_row_index; i++) {
            for(int j=0; j<=max_col_index; j++) {
                visited_list.clear();
                traverse(matrix, i, j, -1, visited_list);
            }
        }
        
        return longest_path;
    }
    
    int traverse(vector<vector<int>>& matrix, int row, int col, int prev_val, set<pair<int,int>> visited_list) {
        
        if(row < 0 || col < 0 || row > max_row_index || col > max_col_index) return 0;
        if(prev_val >= matrix[row][col]) return 0;
        if(memo.find(pair<int,int>{row,col}) != memo.end()) return memo[pair<int,int>{row,col}];
        
        visited_list.insert(pair<int,int>{row,col});
        
        int local_max_len = 0;
        int path_len;
        for(int i=0; i<4; i++) {
            if( visited_list.find(pair<int,int>{row + next_vector[i][0], col + next_vector[i][1]}) != visited_list.end() ) continue;
            path_len = traverse(matrix, row + next_vector[i][0], col + next_vector[i][1], matrix[row][col], visited_list);
            if(path_len > local_max_len) local_max_len = path_len;
        }
        
        if(local_max_len + 1 > longest_path) longest_path = local_max_len + 1;
        
        memo[pair<int,int>{row,col}] = local_max_len + 1;
        
        return local_max_len + 1;
        
    }
    
    
};
