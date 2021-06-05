class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int max_rows = matrix.size();
        int max_cols = matrix[0].size();
        
        int left = 0;
        int right = max_rows * max_cols - 1;
        int mid;
        
        int i,j;
        
        while(left <= right) {
            mid = left + (right - left) / 2 ;
            
            //getRowAndCol(mid, max_cols, i, j);
            i = mid / max_cols;
            j = mid % max_cols;
            
            if(matrix[i][j] == target) {
                
                return true;
                
            } else if(matrix[i][j] < target) {
                
                left = mid + 1;
                
            } else {
                
                right = mid - 1;
                
            }
            
        }
        
        return false;
    }
    
    void getRowAndCol(int cell_num, int max_cols, int &row, int &col) {
        
        row = cell_num / max_cols;
        col = cell_num % max_cols;
        
    }
};
