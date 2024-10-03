class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        long long total_sum_positive_mod = 0;
        for(int i=0; i<nums.size(); i++) {
            total_sum_positive_mod = (total_sum_positive_mod + nums[i]) % p;
        }

        if(total_sum_positive_mod == 0) return 0;
        
        long long current_sum_mod = 0;
        map<int,int> mod_index_map;
        mod_index_map[0] = -1;
        int min_sub_array = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            current_sum_mod = (current_sum_mod + nums[i]) % p;
            int needed = (current_sum_mod - total_sum_positive_mod + p) % p;

            if(mod_index_map.find(needed) != mod_index_map.end()) {
                int sub_array_size = i - mod_index_map[needed];
                if(min_sub_array > sub_array_size) {
                    min_sub_array = sub_array_size;
                }
            }

            mod_index_map[current_sum_mod]  = i;
        }

        if(min_sub_array == nums.size()) return -1;

        return min_sub_array;
    }
};
