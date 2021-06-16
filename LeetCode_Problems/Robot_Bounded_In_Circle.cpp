class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        int x = 0, y = 0;
        
        int direction = 1; // 1 North -1 south 2 East -2 west
        
        for(int i=0; i<4; i++) { // After at most 4 cycles, the limit cycle trajectory returns to the initial point x = 0, y = 0
            for(char d : instructions) {

                if(d == 'G') {

                    if(direction == 1) {
                        y++;
                    } else if(direction == -1) {
                        y--;
                    } else if(direction == 2) {
                        x++;
                    } else if(direction == -2) {
                        x--;
                    }

                } else if (d == 'L') {

                    if(direction == 1) {
                        direction = -2;
                    } else if(direction == -1) {
                        direction = 2;
                    } else if(direction == 2) {
                        direction = 1;
                    } else if(direction == -2) {
                        direction = -1;
                    }                

                } else if (d == 'R') {

                    if(direction == 1) {
                        direction = 2;
                    } else if(direction == -1) {
                        direction = -2;
                    } else if(direction == 2) {
                        direction = -1;
                    } else if(direction == -2) {
                        direction = 1;
                    }
                }
            }
            
            if(x == 0 && y == 0) return true;
        }
        
        return false;
        
    }
};
