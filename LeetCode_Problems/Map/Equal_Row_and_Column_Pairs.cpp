class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        map<string, int> row_nums;

        int num_matching_pairs = 0;

        for(int i=0; i<grid.size(); i++) {

            string row_num = "";
            string col_num = "";
            for(int j=0; j<grid.size(); j++) {
                row_num += to_string(grid[i][j]) + to_string(j);
            }

            row_nums[row_num] = row_nums[row_num] + 1;

        }



        for(int i=0; i<grid.size(); i++) {

            string col_num = "";
            for(int j=0; j<grid.size(); j++) {
                col_num += to_string(grid[j][i]) + to_string(j);
            }

            if(row_nums.find(col_num) != row_nums.end()) {
                num_matching_pairs += row_nums[col_num];
            }
        }


        return num_matching_pairs;
        
    }
};
