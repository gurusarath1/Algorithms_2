/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {

        int l = 0;
        int h = nums.size() - 1;
        int p = -1;

        // MAIN IDEA: Pivot might be in the sorted half
        // Keep updating the pivot in the sorted half

        while(l <= h) {
            int m = l + (h - l) / 2;

            if(nums[l] <= nums[m]) { // Left side sorted
                if(p==-1 || (nums[l] < nums[p])) p = l;
                l = m + 1;
            } else { // Right side sorted
                if(p==-1 || (nums[m] < nums[p])) p = m;
                h = m - 1;
            }
        }
        
        return nums[p];
    }
};
