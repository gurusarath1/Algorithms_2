class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int g = 1; // Guard
        int gg = 3; // Guarded
        int w = 2; // Wall
        int u = 0; // Unguarded
        long long count = m*n;
        vector<vector<int>> grid(m, vector<int>(n, u));

        // Place walls
        for(int i=0; i<walls.size(); i++) {
            int row = walls[i][0];
            int col = walls[i][1];
            grid[row][col] = w;
            count--;
        }

        // Place guards
        for(int i=0; i<guards.size(); i++) {
            int row = guards[i][0];
            int col = guards[i][1];
            grid[row][col] = g;
            count--;
        }

        // Guard watch range
        for(int i=0; i<guards.size(); i++) {
            int row = guards[i][0];
            int col = guards[i][1];
            
            // RIGHT
            for(int j=col+1; j<n; j++) {
                if(grid[row][j] == w || grid[row][j] == g) break;
                if(grid[row][j] == u) {
                    grid[row][j] = gg;
                    count--;
                }
            }
            // LEFT
            for(int j=col-1; j>=0; j--) {
                if(grid[row][j] == w || grid[row][j] == g) break;
                if(grid[row][j] == u) {
                    grid[row][j] = gg;
                    count--;
                }
            }
            // DOWN
            for(int j=row+1; j<m; j++) {
                if(grid[j][col] == w || grid[j][col] == g) break;
                if(grid[j][col] == u) {
                    grid[j][col] = gg;
                    count--;
                }
            }
            // UP
            for(int j=row-1; j>=0; j--) {
                if(grid[j][col] == w || grid[j][col] == g) break;
                if(grid[j][col] == u) {
                    grid[j][col] = gg;
                    count--;
                }
            }
        }

        return count;
    }
};
