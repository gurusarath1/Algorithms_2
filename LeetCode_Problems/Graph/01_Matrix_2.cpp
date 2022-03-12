class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue<vector<int>> q;
        vector<vector<bool>> mat_added(mat.size(), vector(mat[0].size(), false));
        vector<vector<int>> result(mat.size(), vector(mat[0].size(), 0));
        
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j] == 0) {
                    q.push( {i,j} );
                    mat_added[i][j] = true;
                }
            }
        }
        
        int layer = 0;
        while(!q.empty()) {
            
            int layer_size = q.size();
            
            for(int i=0; i<layer_size; i++) {
                vector<int> current_tile = q.front();
                q.pop();
                int cr = current_tile[0];
                int cc = current_tile[1];
                
                if(mat[cr][cc] == 1) {
                    result[cr][cc] = layer;
                }
                
                if(cr - 1 >= 0 && !mat_added[cr-1][cc]) { q.push( {cr-1, cc} ); mat_added[cr-1][cc] = true; }
                if(cr + 1 < mat.size() && !mat_added[cr+1][cc]) { q.push( {cr+1, cc} ); mat_added[cr+1][cc] = true; }
                if(cc - 1 >= 0 && !mat_added[cr][cc-1]) { q.push( {cr, cc-1} ); mat_added[cr][cc-1] = true; }
                if(cc + 1 < mat[0].size() && !mat_added[cr][cc+1]) { q.push( {cr, cc+1} ); mat_added[cr][cc+1] = true; }
            }
            
            layer++;
        }
        
        return result;
        
    }
};
