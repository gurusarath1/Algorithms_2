class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int num_rows = grid.size();
        int num_cols = grid[0].size();

        int num_negatives = 0;
        // Row by row we check where the negative numbers start
        for(int i=0; i<num_rows; i++) {
            int low = 0;
            int high = grid[0].size() - 1;

            while(low <= high) {
                int mid = low + ((high - low) / 2);
                if(grid[i][mid] < 0) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }


            if(low >= num_cols) num_negatives += 0; // Reched End - No Negative numbers

            num_negatives += (num_cols - low); // all cols to the right are negative numbers
        }

        return num_negatives;
    }
};
