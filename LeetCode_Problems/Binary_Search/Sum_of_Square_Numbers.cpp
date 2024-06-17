class Solution {
public:
    bool judgeSquareSum(int c) {

        for(long a=0; a*a <= c; a++) {
            long b = c - (a*a);

            if(check_if_perfect_square(b)) return true;
        }

        return false;
        
    }

    bool check_if_perfect_square(long num) {
        long start = 0;
        long end = num/2 + 1;

        while(start <= end) {
            long mid = (start + end) / 2;

            if(mid * mid == num) {
                return true;
            } else if(mid * mid > num) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return false;

    }
};
