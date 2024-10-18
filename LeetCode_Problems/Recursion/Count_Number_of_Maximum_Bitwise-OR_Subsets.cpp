class Solution {
public:
    int max_value = INT_MIN;
    int max_value_count = 0;

    int countMaxOrSubsets(vector<int>& nums) {
        get_max_ors_subsets_count(nums, 0, 0);

        return max_value_count;
    }

    void get_max_ors_subsets_count(vector<int>& nums, int current_value, int idx) {

        if(idx >= nums.size()) {
            if(current_value > max_value) {
                max_value = current_value;
                max_value_count = 1;
            } else if(current_value == max_value) {
                max_value_count += 1;
            } else {
                ;
            }

            return;
        }

        get_max_ors_subsets_count(nums, current_value, idx+1);
        current_value |= nums[idx];
        get_max_ors_subsets_count(nums, current_value, idx+1);

    }
};
