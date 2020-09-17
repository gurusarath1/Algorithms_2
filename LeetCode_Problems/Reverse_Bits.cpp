/*
Reverse bits of a given 32 bits unsigned integer.
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t new_num = 0;
        uint32_t mask = 0x80000000;
        
        while(n != 0) {
            if(n & 0x1) {
                new_num = new_num | mask;
            }
            
            mask = mask >> 1;
            n = n >> 1;
        }
        
        return new_num;
        
    }
};
