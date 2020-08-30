/*

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1

Example 2:
Input: [4,1,2,1,2]
Output: 4

*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i = i + 2) // traverse the array in steps of 2
        {
            if(nums[i] != nums[i-1])
            {
                return nums[i-1];
            }
        }
        return nums[nums.size() - 1]; //The single sumber is at the end of the array
    }
};
