/*
Given an array of integers nums and and integer target, return the indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1]

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int>mapX;
        vector<int> indices;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(mapX[target - nums[i]] > 0)
            {
                indices.push_back(mapX[target - nums[i]] - 1);
                indices.push_back(i);
                return indices;
            }
            mapX[nums[i]] = i+1;
        }
        return indices;   
    }
};
