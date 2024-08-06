/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {

        int low = 0;
        int high = reader.length() - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;
            int comp_result;
            int odd_len_array = ( (low - high + 1) & 1 );

            // Array size is 2 (special case to prevent infinite looping because of low=mid and high=mmid case)
            if( (high - low) == 1) {
                if(reader.compareSub(low,low, high,high) > 0 ) {
                    return low;
                } else {
                    return high;
                }
            }
    
            // Make sure to compare two equal length arrays
            if( odd_len_array ) {
                comp_result = reader.compareSub(low,mid, mid,high);
            } else {
                comp_result = reader.compareSub(low,mid, mid+1,high);
            }


            if(comp_result == 0) {
                return mid;
            } else if (comp_result > 0) {
                if(odd_len_array) high = mid - 1; // mid is not the largest number
                else high = mid;
            } else {
                if(odd_len_array) low = mid + 1; // mid is not the largest number
                else low = mid;
            }

        }

        return 0; //  The largest number is at the beginning
    }
};
