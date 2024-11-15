class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        int size = arr.size();

        int left_end = 0;
        while(left_end < arr.size()-1 && arr[left_end] <= arr[left_end+1]) {
            left_end++;
        }

        int right_begin = arr.size() - 1;
        while(right_begin >= 1 && arr[right_begin-1] <= arr[right_begin]) {
            right_begin--;
        }

        if(left_end == arr.size()-1 && right_begin == 0) { // ascending order
            return 0;
        }

        int min_len = INT_MAX;
        for(int i=0; i<=left_end; i++) {

            int low = right_begin;
            int high = arr.size() - 1;
            int target = arr[i]; // assuming arr[i] on the left is included

            while(low <= high) {
                int mid = low + (high-low) / 2;
                if(arr[mid] >= target) {
                    high = mid - 1;
                    if(min_len > mid - i - 1) min_len = mid - i - 1;
                } else {
                    low = mid + 1;
                }
            }

        }

        if(min_len > arr.size() - (left_end+1)) { // Delete full right
            min_len = arr.size() - (left_end+1);
        }

        if(min_len > (right_begin)) { // Delete full left
            min_len = right_begin;
        }

        return min_len;
    }
};
