class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int low = 0;
        int high = arr.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int num_numbers_missing_to_left = arr[mid] - mid - 1;

            if (num_numbers_missing_to_left >= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Missing number is at the start of the array
        // Array starts with a value greater than k
        if(high == -1) {
            return k;
        }

        //Now the missing number is between the high and low index
        // arr[high] + (Number remaining elements)
        // arr[high] + (k - Num missing to the left)
        return arr[high] + k - (arr[high] - high - 1);
        
    }
};
