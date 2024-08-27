class Solution {
public:
    double get_median(vector<int>& sorted_array) {

        if(sorted_array.size() % 2 == 0) {
            return ((double)sorted_array[ (sorted_array.size() / 2) ] + (double)sorted_array[ (sorted_array.size() / 2) - 1 ]) / (double)2;
        } else {
            return (double)sorted_array[ (sorted_array.size() / 2) ];
        }

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() == 0) {
            return get_median(nums2);
        }

        if(nums2.size() == 0) {
            return get_median(nums1);
        }


        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays_remastered(nums1, nums2);
        } else {
            return findMedianSortedArrays_remastered(nums2, nums1);
        }

        return 0;
        
    }


    double findMedianSortedArrays_remastered(vector<int>& big_array, vector<int>& small_array) {

        int size1 = big_array.size();
        int size2 = small_array.size();
        int max_size = max(size1, size2);
        int total_size = size1 + size2;

        int low = -1; // take none from big array for LEFT side of the full length array
        int high = max_size - 1; // take all from big array for LEFT side of the full length array

        int num_elements_on_left = total_size / 2;
        int num_elements_on_right = total_size - num_elements_on_left;

        // We are finding the left half of the full length array

        // left_side_l1 = Index of last element from big array 
        // left_side_l2 = Index of last element from small array
        // right_side_l1 = Index of first element from big array 
        // right_side_l2 = Index of first element from small array

        int left_side_l1;
        int left_side_l2;
        int right_side_l1;
        int right_side_l2;

        while(low <= high) {

            int mid = low + (high - low) / 2; // take mid+1 number of elements from big_array;

            left_side_l1 = mid;
            right_side_l1 = left_side_l1 + 1;
            int num_elements_from_big_array = mid+1; // mid is the index of last element

            // calculate number of elements from small_array
            int num_elements_from_small_array;
            if(num_elements_on_left - num_elements_from_big_array <= 0 ) {
                num_elements_from_small_array = 0;
            } else {
                num_elements_from_small_array = num_elements_on_left - num_elements_from_big_array;
            }

            left_side_l2 = num_elements_from_small_array - 1;
            right_side_l2 = left_side_l2 + 1;

            if(num_elements_from_small_array > size2) {
                low = mid + 1;
                continue;
            }

            int valid_split = true;

            // Invalid case 1
            if(left_side_l1 >= 0 && left_side_l1 < size1 && right_side_l2 >= 0 && right_side_l2 < size2) {
                if(big_array[left_side_l1] > small_array[right_side_l2]) {
                    high = mid - 1;
                    valid_split = false;
                }
            }
            
            // Invalid case 2
            if(left_side_l2 >= 0 && left_side_l2 < size2 && right_side_l1 >= 0 && right_side_l1 < size1) {
                if(small_array[left_side_l2] > big_array[right_side_l1]) {
                    low = mid + 1;
                    valid_split = false;
                }
            }

            if(valid_split) {
                // If it is a valid split, we want to see if we can find a smaller valid split
                high = mid - 1;
            }

        }

        left_side_l1 = low; // Low points to the end of left split in the big array
        right_side_l1 = low + 1; // right split starts from the next index
        left_side_l2 = num_elements_on_left - low -2;
        right_side_l2 = left_side_l2 + 1;

        // Even Array case
        if(total_size % 2 == 0) {

            double left_max = INT_MIN; // mid value 1
            double right_min = INT_MAX; // mid value 2

            // Find the largest in the left split
            if(left_side_l1 >= 0 && left_side_l1 < size1) {
                left_max = big_array[left_side_l1];
            }
            if(left_side_l2 >= 0 && left_side_l2 < size2) {
                if(left_max < small_array[left_side_l2]) left_max = small_array[left_side_l2];
            }

            // Find the smallest in the right split
            if(right_side_l1 >= 0 && right_side_l1 < size1) {
                right_min = big_array[right_side_l1];
            }
            if(right_side_l2 >= 0 && right_side_l2 < size2) {
                if(right_min > small_array[right_side_l2]) right_min = small_array[right_side_l2];
            }

            return (left_max + right_min) / 2; // Average of both the mid values


        } else { // Odd array case

            if(right_side_l1 >= 0 && right_side_l1 < size1 && right_side_l2 >= 0 && right_side_l2 < size2) {
                return min(big_array[right_side_l1], small_array[right_side_l2]);
            } else if (right_side_l1 >= 0 && right_side_l1 < size1) {
                return big_array[right_side_l1]; // Big array is completely on the the right
            } else {
                small_array[right_side_l2]; // Small array is completely on the the right
            }

        }


        return 0;

    }
};
