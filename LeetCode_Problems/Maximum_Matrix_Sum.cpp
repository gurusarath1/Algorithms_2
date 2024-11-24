class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        int smallest_num_in_col = INT_MAX;
        int num_negative_num = 0;
        long long best_sum = 0;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(smallest_num_in_col > abs(matrix[i][j])) {
                    smallest_num_in_col = abs(matrix[i][j]);
                }
                if(matrix[i][j] < 0) {
                    num_negative_num++;
                }
                best_sum += abs(matrix[i][j]);
            }
        }

        if(num_negative_num & 1) {
            best_sum -= smallest_num_in_col;
            best_sum -= smallest_num_in_col;
        }

        return best_sum;
    }
};
