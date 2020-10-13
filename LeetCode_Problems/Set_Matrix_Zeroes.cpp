/*


*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        map<int, int> rows;
        map<int, int> cols;
        
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        
        map<int, int>::iterator map_iter;
        
        map_iter = rows.begin();
        while(map_iter != rows.end()) {
            if(map_iter->second != 0) {
                for(int i=0; i<matrix[0].size(); i++) {
                    matrix[map_iter->first][i] = 0;
                }
            }
            
            map_iter++;
        }
        
        map_iter = cols.begin();
        while(map_iter != cols.end()) {
            if(map_iter->second != 0) {
                for(int i=0; i<matrix.size(); i++) {
                    matrix[i][map_iter->first] = 0;
                }
            }
            
            map_iter++;
        }
    }
};
