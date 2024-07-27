class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == nums[low] && nums[mid] == nums[high]) {
                // Can't decide to go left or right
                // But we know for sure nums[high] is not the pivot
                high -= 1;
            } else if(nums[mid] <= nums[high]) {
                // Right is sorted (you can't do similar thing if left is sorted because pivot can be left)
                // Go left
                high = mid;
            } else {
                // Right is not sorted. Left may or may not be sorted
                // Go Right
                low = mid + 1; // mid is not the pivot
            }
        }
        
        return nums[low];
    }
};
