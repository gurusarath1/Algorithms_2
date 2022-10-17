class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int max_rows = mat.size();
        int max_cols = mat[0].size();
        
        int num_diag_elements = min(max_rows, max_cols);
        
        int sum = 0;
        
        int row_1 = 0;
        int col_1 = 0;

        int row_2 = 0;
        int col_2 = mat[0].size() - 1;
        for(int i=0; i<num_diag_elements; i++) {
            
            if(row_1 == row_2 && col_1 == col_2) {
                ; // The center element is counted only once
            } else {
                // Major diag sum
                sum += mat[row_1][col_1];
            }
            row_1++;
            col_1++;
            
            // Minor diag sum
            sum += mat[row_2][col_2];
            row_2++;
            col_2--;
        }
        
        return sum;
    }
};
