class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int num_paths[m][n];
        
        for(int i=0; i<m; i++) num_paths[i][0] = 1;
        for(int i=0; i<n; i++) num_paths[0][i] = 1;
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                num_paths[i][j] = num_paths[i - 1][j] + num_paths[i][j - 1];
        
        return num_paths[m-1][n-1];
    }
};
