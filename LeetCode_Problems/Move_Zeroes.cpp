/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int num_zeros = 0;
        for(unsigned i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                num_zeros += 1;
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        
        for(int i=0; i<num_zeros; i++)
        {
            nums.push_back(0);
        }
        
    }
};
