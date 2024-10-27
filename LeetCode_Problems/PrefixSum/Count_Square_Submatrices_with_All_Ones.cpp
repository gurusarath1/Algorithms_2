class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int num_rows = matrix.size();
        int num_cols = matrix[0].size();
        // 2D Prefix Sum
        for(int i=1; i<num_rows; i++) {
            matrix[i][0] += matrix[i-1][0];
        }
        for(int i=1; i<num_cols; i++) {
            matrix[0][i] += matrix[0][i-1];
        }
        for(int i=1; i<num_rows; i++) {
            for(int j=1; j<num_cols; j++) {
                matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
            }
        }

        int total_squares = matrix[num_rows-1][num_cols-1]; // Number of 1x1 squares (number of ones)
        // Loop from squares of size 2x2
        for(int square_len=2; square_len<=num_rows; square_len++) {

            int square_area = square_len * square_len;

            for(int i=0; i<num_rows; i++) {
                for(int j=0; j<num_cols; j++) {
                    // Check if square is possible starting form this index i,j = (top left corner)
                    if( ((i+square_len-1) < num_rows) && ((j+square_len-1) < num_cols) ) { // bottom right corner
                        // Count the number of ones in this square section
                        int num_ones = matrix[i + square_len - 1][j + square_len - 1];
                        if(i-1 >=0) {
                            num_ones -= matrix[i-1][j+square_len-1];
                        }
                        if(j-1 >= 0) {
                            num_ones -= matrix[i+square_len-1][j-1];
                        }
                        if(i-1 >=0 && j-1 >= 0) {
                            num_ones += matrix[i-1][j-1]; // This term was substracted twice so add it back.
                        }

                        // if number of ones equal to area, then it is a square
                        if(num_ones == square_area) total_squares++;
                    }
                }
            }

        }

        return total_squares;
    }
};
