/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length)
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l=0;
        int h = nums.size() - 1;

        while(l <= h) {
            int m = l + (h - l) / 2;

            if(nums[m] == target) return m;

            // In <= the equal (=) is important because l might be equal m.
            if(nums[l] <= nums[m]) { // left side is sorted

                if(nums[l] <= target && target < nums[m]) { // target on left side
                    h = m - 1;
                } else {
                    l = m + 1;
                }

            } else { // right side is sorted

                if(nums[m] < target && target <= nums[h]) { // target on right side
                    l = m + 1;
                } else {
                    h = m - 1;
                }

            }
        }

        return -1;
    }
};
