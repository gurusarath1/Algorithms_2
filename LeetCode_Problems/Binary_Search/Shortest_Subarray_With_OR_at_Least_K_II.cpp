class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {

        vector<int> bit_count(31, 0);

        int low = 1;
        int high = nums.size();
        int best_possible = -1;
        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(is_k_possible_with_this_size(nums, k, mid)) {
                best_possible = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }

        }

        return best_possible;
    }

    int bit_count_to_num(vector<int> bit_count) {

        int num = 0;
        for(int i=0; i<bit_count.size(); i++) {
            if(bit_count[i] >= 1) {
                num |= (1 << i);
            }
        }

        return num;

    }

    bool is_k_possible_with_this_size(vector<int> &nums, int k, int size) {

        vector<int> bit_count(31, 0);

        for(int i=0; i<size; i++) {
            int num = nums[i];

            int bit_pos = 0;
            while(num) {
                int bit = num & 1;
                num = num >> 1;
                if(bit) bit_count[bit_pos] += 1;
                bit_pos++;
            }
        }

        int current_num_in_window = bit_count_to_num(bit_count);
        if(current_num_in_window >= k) return true;

        int index_to_remove = 0;
        for(int i=size; i<nums.size(); i++) {
            int num_to_remove = nums[index_to_remove++];
            int num_to_or = nums[i];

            int bit_pos = 0;
            while(num_to_remove) {
                int bit = num_to_remove & 1;
                num_to_remove = num_to_remove >> 1;
                if(bit) bit_count[bit_pos] -= 1;
                bit_pos++;
            }

            bit_pos = 0;
            while(num_to_or) {
                int bit = num_to_or & 1;
                num_to_or = num_to_or >> 1;
                if(bit) bit_count[bit_pos] += 1;
                bit_pos++;
            }

            current_num_in_window = bit_count_to_num(bit_count);
            if(current_num_in_window >= k) return true;

        }

        return false;
    }
};
