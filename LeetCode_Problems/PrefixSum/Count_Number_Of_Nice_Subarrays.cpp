class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int num_subarrays_with_3_odd_nums = 0;
        int prefix_sum =0;
        map<int, int> prefix_sum_index_map;

        prefix_sum_index_map[prefix_sum] = 1;

        for(int i=0; i<nums.size(); i++) {
            prefix_sum += nums[i] & 1;

            if(prefix_sum_index_map.find(prefix_sum - k) != prefix_sum_index_map.end()) {
                num_subarrays_with_3_odd_nums += prefix_sum_index_map[prefix_sum -k];
            }

            prefix_sum_index_map[prefix_sum] += 1;
        }

        return num_subarrays_with_3_odd_nums;
    }
};
