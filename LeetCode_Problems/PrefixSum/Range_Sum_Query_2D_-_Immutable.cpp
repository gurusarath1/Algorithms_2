/*
Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) 
and lower right corner (row2, col2).

Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside 
the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.
*/

class NumMatrix {
public:
    vector<vector<int>> matrix_prefix_sum;

    NumMatrix(vector<vector<int>>& matrix) {

        int n_rows = matrix.size();
        int n_cols = matrix[0].size();

        matrix_prefix_sum = vector<vector<int>>(n_rows, vector<int>(n_cols));

        for(int i=0; i<n_rows; i++) {
            int sum = 0;
            for(int j=0; j<n_cols; j++) {
                sum += matrix[i][j];
                matrix_prefix_sum[i][j] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        int sum = 0;
        for(int i=row1; i<=row2; i++) {
            if(col1 != 0)
            {
                sum += matrix_prefix_sum[i][col2] - matrix_prefix_sum[i][col1 - 1];
            } else {
                sum += matrix_prefix_sum[i][col2];
            }
        }
        
        return sum;
    }
};
