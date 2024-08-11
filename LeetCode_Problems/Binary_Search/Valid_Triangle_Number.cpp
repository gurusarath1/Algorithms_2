class Solution {
public:

    int binary_search(vector<int> &nums, int low, int high, int target) {

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;

    }

    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int total_num_triplets = 0;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {

                // Binary Search the third numbers -----------

                if(j == nums.size() - 1) break;

                int sum =  nums[i] + nums[j];

                // Get the index of number just greater than or equal to the sum
                int from_idx_to_not_include = binary_search(nums, j+1, nums.size() - 1, sum);

                int num_triplets = (from_idx_to_not_include -j -1); // Count number of numbers less than sum

                total_num_triplets += num_triplets;

            }
        }

        return total_num_triplets;
    }
};
