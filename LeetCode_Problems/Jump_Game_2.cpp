/*

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2

*/


class Solution {
public:
    int jump(vector<int>& nums) {
        
        vector<int> memo(nums.size(), -1);
        
        return support_jump(nums, 0, memo);
        
    }
    
    int support_jump(vector<int>& nums, int index, vector<int> &memo) {
        
        if(index == nums.size()-1) {
            return 0;
        }
        
        if(memo[index] != -1) {
            return memo[index];
        }
        
        int jumps, min_jumps = nums.size() + 1;
        
        for(int i=1; i<=nums[index]; i++) {
            
            if(index + i < nums.size()){
                jumps = 1 + support_jump(nums, index + i, memo);
                
                if(jumps < min_jumps) {
                    min_jumps = jumps;
                }
            }
            
        }
        
        memo[index] = min_jumps;
        
        return memo[index];
        
    }
};
