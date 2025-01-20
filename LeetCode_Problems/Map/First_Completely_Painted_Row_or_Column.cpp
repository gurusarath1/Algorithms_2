class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int num_rows = mat.size();
        int num_cols = mat[0].size();

        vector<pair<int,int>> loc(num_rows*num_cols+1);
        for(int i=0; i<num_rows; i++) {
            for(int j=0; j<num_cols; j++) {
                loc[mat[i][j]] = pair<int,int>{i,j};
            }
        }

        vector<int> row_paint(num_rows, 0);
        vector<int> col_paint(num_cols, 0);
        for(int i=0; i<arr.size(); i++) {
            row_paint[ loc[arr[i]].first ] += 1;
            col_paint[ loc[arr[i]].second ] += 1;

            if(row_paint[ loc[arr[i]].first ] == num_cols || col_paint[ loc[arr[i]].second ] == num_rows) {
                return i;
            }
        }

        return -1;
    }
};
