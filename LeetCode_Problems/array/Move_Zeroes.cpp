/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        for(int i=nums.size()-1; i>=0; i--) {
            if(nums[i] == 0) {
                int j = i;
                while(nums[j] == 0 && j!=nums.size() - 1) {
                    nums[j] = nums[j+1];
                    if(nums[j+1] == 0)break;
                    nums[j+1] = 0;
                    j++;
                }
            }
        }
        return;
    }
};
