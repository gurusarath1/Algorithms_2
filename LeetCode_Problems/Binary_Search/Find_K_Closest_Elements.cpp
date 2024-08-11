class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        // Step 1: Find the first closest element to x

        int low = 0;
        int high = arr.size() - 1;
        int first_closest_num_index = -1;
        int sub_arry_start_index = -1;
        int sub_arry_end_index = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] == x) {
                first_closest_num_index = mid; // If x is found, then mid index is the first closest index
                break;
            } else if(arr[mid] > x) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // If x is not in the array, index high or low will have the first closest number
        if(first_closest_num_index == -1) {
            
            if(high == -1) { // x less than all elements in the array
                first_closest_num_index = low;
            } else if (low == arr.size()) { // x greater than all elements in the array
                first_closest_num_index = high;
            } else if( abs(arr[high] - x) > abs(arr[low] - x) ) { // high or low index is the closest
                first_closest_num_index = low;
            } else {
                first_closest_num_index = high;
            }
        }

        vector<int> ret;

        if(high == -1) { // first k elements
            sub_arry_start_index = first_closest_num_index;
            sub_arry_end_index = k - 1;
        } else if(low == arr.size()) { // last k elements
            sub_arry_start_index = first_closest_num_index - k + 1;
            sub_arry_end_index = first_closest_num_index;
        } else {

            // Step 2: Two pointer algo to find the range

            int ptr_1 = first_closest_num_index - 1;
            int ptr_2 = first_closest_num_index + 1;
            int num_values_collected = 1; // 1 value already collected (first closest number)

            while(num_values_collected < k) {
                if( abs(arr[ptr_1] - x) > abs(arr[ptr_2] - x) ) {
                    ptr_2++;
                    num_values_collected++;

                    // reached end of array ?
                    if(ptr_2 == arr.size()) {
                        ptr_1 -= (k - num_values_collected);
                        num_values_collected = k;
                        break;
                    }
                } else {
                    ptr_1--;
                    num_values_collected++;

                    // reached the beginning of array ?
                    if(ptr_1 == -1) {
                        ptr_2 += (k - num_values_collected);
                        num_values_collected = k;
                        break;
                    }
                }
            }

            // Start and end indices
            sub_arry_start_index = ptr_1 + 1;
            sub_arry_end_index = ptr_2 - 1;
        }

        // Create the subarray;
        for(int i=sub_arry_start_index; i<=sub_arry_end_index; i++) {
            ret.push_back(arr[i]);
        }
        return ret;
        
    }
};
