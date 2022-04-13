class Solution {
public:
    
    #define LEFT 0
    #define RIGHT 1
    #define UP 2
    #define DOWN 3
    
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> result(n, vector<int>(n,0));
        
        int val = 1;
        
        int i = 0;
        int j = 0;
        int state = RIGHT;
        bool state_updated = false;
        while(val <= n*n && result[i][j] == 0) {
            result[i][j] = val;
            val++;
            
            // Determine the next direction
            switch(state) {
                case RIGHT:
                    
                    if(!(j+1 <= n-1 && result[i][j+1] == 0)) state = DOWN;
                    
                    break;
                case DOWN:
                    
                    if(!(i+1 <= n-1 && result[i+1][j] == 0)) state = LEFT;
                    
                    break;
                case LEFT:
                    
                    if(!(j-1 >= 0 && result[i][j-1] == 0)) state = UP;
                    
                    break;
                case UP:
                    
                    if(!(i-1 >= 0 && result[i-1][j] == 0)) state = RIGHT;
                    
                    break;
                default:
                    break;
            }
            
            // Goto next tile
            if(state == RIGHT) {
                j++;
            } else if(state == DOWN) {
                i++;
            } else if(state == LEFT) {
                j--;
            } else if(state == UP) {
                i--;
            }
            
        }
        
        
        return result;
        
    }
};
