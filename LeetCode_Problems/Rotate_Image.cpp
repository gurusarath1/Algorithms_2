class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int temp;
        
        
        // Transpose the matrix
        for(int i=0; i<matrix.size(); i++) {
            
            for(int j=i; j<matrix[0].size(); j++) {
                
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
                
            }
            
        }
        
        // Flip the matrix horizontally
        for(int i=0; i<matrix.size(); i++) {
            
            int pointer1 = 0;
            int pointer2 = matrix[0].size() - 1;
            for(int k=0; k<matrix[0].size() / 2; k++) {
                
                temp = matrix[i][pointer1];
                matrix[i][pointer1] = matrix[i][pointer2];
                matrix[i][pointer2] = temp;
                
                pointer1++;
                pointer2--;
            }
            
        }
        
    }
};
