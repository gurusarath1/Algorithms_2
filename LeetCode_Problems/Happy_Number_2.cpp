class Solution {
public:
    bool isHappy(int n) {
        
        map<int,int> visitedNums;
        int slow_ptr = n;
        int fast_ptr = n;
        
        do {
            
            slow_ptr = nextNumInSeq(slow_ptr);
            fast_ptr = nextNumInSeq(nextNumInSeq(fast_ptr));
            
        } while(slow_ptr != fast_ptr);
        
        if(slow_ptr == 1) return true;
        
        return false;
        
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
