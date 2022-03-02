/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    
    int array_size;
    
    int search(const ArrayReader& reader, int target) {
        
        int left = 0;
        int right = INT_MAX;
        int mid;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            
            if(left == right && mid == left) {
                array_size = mid;
                break;
            }
            
            if(reader.get(mid) == INT_MAX) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        left = 0;
        right = array_size;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            
            if(reader.get(mid) == target) {
                return mid;
            }
            
            else if( reader.get(mid) > target ) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            
        }

        return -1;
    }
};
