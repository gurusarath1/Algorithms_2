class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int n = mat.size();
        
        bool checks[4] = {true, true, true, true};
        
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                
                if(mat[i][j] != target[i][j]) checks[0] = false;
                if(mat[i][j] != target[j][n - 1 - i]) checks[1] = false;
                if(mat[i][j] != target[n - 1 - i][n - 1 - j]) checks[2] = false;
                if(mat[i][j] != target[n - 1 - j][i]) checks[3] = false;
                
            }
        }
        
        return checks[0] || checks[1] || checks[2] || checks[3];
        
    }
};
