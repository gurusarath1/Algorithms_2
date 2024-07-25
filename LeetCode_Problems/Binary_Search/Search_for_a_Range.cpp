class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ret;


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

        if(low < nums.size() && nums[low] == target) {
            ret.push_back(low);
        }  else {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }

        low = 0;
        high = nums.size() - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        }

        ret.push_back(high);


        return ret;
    }
};
