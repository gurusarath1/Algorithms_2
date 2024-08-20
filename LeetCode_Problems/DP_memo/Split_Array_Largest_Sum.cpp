class Solution {
public:

   // TIME LIMIT EXCEEDS

    vector<int> prefixSum;
    int memo[1001][51];

    int splitArrayRec(vector<int> &prefix_sum, int current_start_index, int current_end_index, int num_subarrays) {

        if(current_end_index == prefix_sum.size() - 2 && num_subarrays > 1) {
            return INT_MAX;
        }

        if( (prefix_sum.size() - current_end_index - 1) < num_subarrays) {
            return INT_MAX;
        }

        if(num_subarrays == 1) {
            return prefix_sum[prefix_sum.size() - 1] - prefix_sum[current_start_index];
        }

        if(memo[current_start_index][num_subarrays] != 0) {
            return memo[current_start_index][num_subarrays];
        }

        int extended_sum = splitArrayRec(prefix_sum, current_start_index, current_end_index+1, num_subarrays);

        int end_here_sum_later = splitArrayRec(prefix_sum, current_end_index+1, current_end_index+1, num_subarrays - 1);
        int end_here_sum = prefix_sum[current_end_index + 1] - prefix_sum[current_start_index];

        memo[current_start_index][num_subarrays] = min(extended_sum, max(end_here_sum, end_here_sum_later));

        return memo[current_start_index][num_subarrays];
    }

    int splitArray(vector<int>& nums, int k) {

        int sum = 0;
        prefixSum.resize(nums.size() + 1);
        prefixSum[0] = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            prefixSum[i+1] = sum;
        }
        return splitArrayRec(prefixSum, 0, 0, k);
    }
};
