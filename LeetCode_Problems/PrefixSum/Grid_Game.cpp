class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        int num_cols = grid[0].size();

        vector<vector<long long>> prefix_suffix_sum(2, vector<long long>(num_cols, 0));

        // row 0 suffix sum
        prefix_suffix_sum[0][num_cols-1] = grid[0][num_cols-1];
        for(int i=num_cols-2; i>=0; i--) {
            prefix_suffix_sum[0][i] = prefix_suffix_sum[0][i+1] + (long long)grid[0][i];
        }
        
        // row 1 prefix sum
        prefix_suffix_sum[1][0] = grid[1][0];
        for(int i=1; i<num_cols; i++) {
            prefix_suffix_sum[1][i] = prefix_suffix_sum[1][i-1] + (long long)grid[1][i];
        }


        long long max_robot2_points = 0x7FFFFFFFFFFFFFFF;
        for(int i=0; i<num_cols; i++) {

            long long points_if_row0_taken_by_robo1 = 0;
            long long points_if_row1_taken_by_robo1 = 0;

            if(i+1 < num_cols) {
                points_if_row0_taken_by_robo1 = prefix_suffix_sum[0][i+1];
            }

            if(i-1 >= 0) {
                points_if_row1_taken_by_robo1 = prefix_suffix_sum[1][i-1];
            }

            max_robot2_points = min(max_robot2_points, max(points_if_row0_taken_by_robo1, points_if_row1_taken_by_robo1));
        }

        return max_robot2_points;
    }
};
