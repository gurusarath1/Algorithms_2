class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int sqrt_max = num / 2;
        
        long long int left = 0;
        long long int right =sqrt_max;
        
        if(num == 1) return true;
        
        while(left <= right) {
            
            long long int mid = left + (right - left) / 2;
            
            if(mid *  mid == num) {
                return true;
            }
            
            if(mid * mid > num) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            
        }
        
        return false;
        
    }
};
