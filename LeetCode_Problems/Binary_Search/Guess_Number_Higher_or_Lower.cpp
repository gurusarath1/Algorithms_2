/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        int start = 1;
        int end = n;
        int mid;
        
        while(start <= end) {
            mid = start + (end - start) / 2;
            
            int gs = guess(mid);
            
            if(gs == -1) {
                end = mid - 1;
            } else if(gs == 1) {
                start = mid + 1;
            } else {
                return mid;
            }
            
        }
        
        return -1;
        
    }
};
