/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length)
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0;
        int h = nums.size() - 1;

        while(l <= h) {
            int m = l + (h - l) / 2;

            if(nums[m] == target) return true;

            // Only case when we can't find if left or right is sorted because of duplicates
            if(nums[l] == nums[m] && nums[m] == nums[h]) {
                // shrink the search space
                l++;
                h--;
                continue;
            }

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

        return false;
    }
};
