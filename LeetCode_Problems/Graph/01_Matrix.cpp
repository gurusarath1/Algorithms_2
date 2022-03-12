class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        // TIME LIMIT EXCEEDS
        
        auto result = mat;
        
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                
                
                if(mat[i][j] == 1) {
                    
                    bool done_finding_dist = false;
                    
                    vector<vector<bool>> visited( mat.size(), vector<bool>(mat[0].size(), false) );
                    queue<vector<int>> q;
                    q.push( {i,j} );
                    visited[i][j] = true;
                    int shortest_dist = 0;
                    
                    while(!q.empty()) {
                        
                        int layer_size = q.size();
                        shortest_dist++;
                        
                        for(int k=0; k<layer_size; k++) {
                            
                            vector<int> current_tile = q.front();
                            q.pop();
                            int cr = current_tile[0];
                            int cc = current_tile[1];
                            
                            if(mat[cr][cc] == 0) {
                                result[i][j] = shortest_dist - 1;
                                done_finding_dist = true;
                                break;
                            }
                            
                            if(cr - 1 >= 0 && !visited[cr-1][cc]) q.push( {cr-1, cc} );
                            if(cr + 1 < mat.size() && !visited[cr+1][cc]) q.push( {cr+1, cc} );
                            if(cc - 1 >= 0 && !visited[cr][cc-1]) q.push( {cr, cc-1} );
                            if(cc + 1 < mat[0].size() && !visited[cr][cc+1]) q.push( {cr, cc+1} );
                            
                        }
                        
                        if(done_finding_dist) break;
                    }
                    
                } // mat i j = 1
                
                
            }
        }
        
        return result;        
        
    }
};
