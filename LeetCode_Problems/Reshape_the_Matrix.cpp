class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        // Check if reshape possible
        if(r * c != mat.size() * mat[0].size()) return mat;
        
        vector<vector<int>> result( r, vector<int>(c,0) );
        
        int res_row = 0;
        int res_col = 0;
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                result[res_row][res_col] = mat[i][j];
                
                // Update resultant matrix indices
                res_col = (res_col + 1) % c;
                if(res_col == 0) res_row = (res_row + 1) % r;
            }
        }
        
        return result;
    }
};
