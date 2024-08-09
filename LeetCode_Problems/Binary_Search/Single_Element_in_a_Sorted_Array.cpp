class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while(low < high) {

            int mid = low + (high - low) / 2;
            int both_halves_are_odd_length = (high - mid) & 1;

            if(nums[mid] == nums[mid + 1]) {

                if(both_halves_are_odd_length) {
                    high = mid - 1; // Left side is the odd length array
                } else {
                    low = mid + 2; // Right sided is the odd length array
                }

            } else if(nums[mid - 1] == nums[mid]) {

                if(both_halves_are_odd_length) {
                    low = mid + 1; //Right side is the odd length array
                } else {
                    high = mid - 2; //Left side is the odd length array
                }

            } else {
                return nums[mid];
            }

        }

        return nums[high]; // or nums[low] // low == high
        
    }
};
