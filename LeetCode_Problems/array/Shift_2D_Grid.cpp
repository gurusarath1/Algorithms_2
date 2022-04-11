class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        vector<vector<int>> result(grid.size(), vector<int>(grid[0].size()));
        
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        int num_elements = num_rows * num_cols;
        
        for(int i=0; i<num_rows; i++) {
            for(int j=0; j<num_cols; j++) {
                
                int element_num = i * num_cols + j;
                int new_element_num = (element_num + k) % num_elements;
                
                int new_j = (j + k) % num_cols;
                int new_i = (new_element_num - new_j) / num_cols;
                
                result[new_i][new_j] = grid[i][j];
            }
        }
        
        return result;
    }
};
