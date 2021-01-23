/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

    Starting with any positive integer, replace the number by the sum of the squares of its digits.
    Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    Those numbers for which this process ends in 1 are happy.

Return true if n is a happy number, and false if not.
*/

class Solution {
public:
    bool isHappy(int n) {
        
        map<int,int> visitedNums;
        int current_num = n;
        
        while(current_num != 1) {
            
            current_num = nextNumInSeq(current_num);
            
            if(visitedNums[current_num]) {
                return false;
            }
            
            visitedNums[current_num] = 1;
            
        }
        
        return true;
        
    }
    
    int nextNumInSeq(int num) {
        
        int next_num = 0;
        
        while(num != 0) {
            
            next_num += (num % 10) * (num % 10);
            num = num / 10;
            
        }
        
        return next_num;
        
    }
};
