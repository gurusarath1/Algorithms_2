class Solution {
public:

    int num_subarrays_required(vector<int>& nums, int max_sum) {


        int current_sum = 0;
        int num_subarrays = 0;
        for(int n : nums) {

            if(current_sum + n <= max_sum) {
                current_sum += n;
            } else {
                current_sum = n;
                num_subarrays++;
            }

        }

        if(num_subarrays == 0) return 1;

        return num_subarrays;
    }

    int splitArray(vector<int>& nums, int k) {

        int max_val = INT_MIN;
        int full_sum = 0;
        for(int n : nums) {
            max_val = max(max_val, n);
            full_sum += n;
        }

        int low = max_val;
        int high = full_sum;

        while(low <= high) {

            int max_allowed_sum = low + (high - low) / 2;

            int min_num_subarrays_required = num_subarrays_required(nums, max_allowed_sum);

            if(min_num_subarrays_required >= k) {
                low = max_allowed_sum + 1;
            } else {
                high =  max_allowed_sum - 1;
            }

        }

        if(low > full_sum) return full_sum;
        
        return low;
    }
};
