class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {

        vector<int> result;


        // Drop the ball in each column
        for(int col=0; col<grid[0].size(); col++) {

            int row=0;
            int col_copy = col; // temp variable the memo the col index

            // Loop to make the ball go down
            while(1) {

                if(grid[row][col] == 1) {
                    
                    if(col + 1 >= grid[0].size()) {
                        // fell outside (right) before reaching end
                        col = col_copy;
                        result.push_back(-1);
                        break;
                    }

                    if(grid[row][col + 1] == 1) {
                        // Can pass through
                        // Moving right - down
                        row++;
                        col++;
                    } else {
                        // Blocked
                        col = col_copy;
                        result.push_back(-1);
                        break;
                    }

                } else {

                    if(col - 1 < 0) {
                        // fell outside (left) before reaching end
                        col = col_copy;
                        result.push_back(-1);
                        break;
                    }

                    if(grid[row][col - 1] == -1) {
                        // can pass through
                        // Moving left - down
                        row++;
                        col--;
                    } else {
                        // blocked
                        col = col_copy;
                        result.push_back(-1);
                        break;
                    }

                }

                if(row == grid.size()) {
                    // Can out
                    result.push_back(col);
                    col = col_copy;
                    break;                    
                }
    
            }

        }

        return result;
        
    }
};
