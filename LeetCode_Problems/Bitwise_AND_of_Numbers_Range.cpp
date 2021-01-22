class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        int numberOfShifts = 0;
        while(m != n) {
            
            m = m >> 1;
            n = n >> 1;
            numberOfShifts++;
            
        }
        
        return m << numberOfShifts;
        
    }
};
