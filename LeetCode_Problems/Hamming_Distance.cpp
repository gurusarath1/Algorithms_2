/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int diff_num = x ^ y;
        
        int count = 0;
        
        while(diff_num != 0) {
            if(diff_num & 0x1) {
                count++;
            }
            diff_num = diff_num >> 1;
        }
        
        return count;
        
    }
};
