class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ret;

        int start_index = get_start_index(nums, target);
        int end_index = get_end_index(nums, target);

        ret.push_back(start_index);
        ret.push_back(end_index);

        return ret;
    }

    int get_start_index(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }

        }
        if(low == nums.size()) return -1;
        if(nums[low] != target) return -1;

        return low;
    }

    int get_end_index(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }

        }

        if(high == -1) return -1;
        if(nums[high] != target) return -1;

        return high;
    }
};
