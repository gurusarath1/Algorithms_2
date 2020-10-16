/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        
        //return rob_support(nums, 0, 0); // Time limit exceeds with this approach
        
        if(nums.size() == 0) return 0;
        
        if(nums.size() == 1) return nums[0];
        
        int dp_array[nums.size()];
        
        dp_array[0] = nums[0]; // Rob house 0
        dp_array[1] = max(nums[0], nums[1]); // Rob house 1 if house 1 is better than house 0
        for(int i=2; i<nums.size(); i++) {
            
            // Either Rob or don't rob -- Take the max option
            dp_array[i] = max(nums[i] + dp_array[i-2], dp_array[i-1]);
            
        }
        
        return dp_array[nums.size() - 1];
        
        
    }
    
    /*
    Time limit exceeds with this approach
    */
    int rob_support(vector<int>& nums, int current_location, int current_loot) {
        
        if(current_location >= nums.size()) return current_loot;
        
        int loot_1 = rob_support(nums, current_location+2, nums[current_location] + current_loot);
        int loot_2 = rob_support(nums, current_location+1, current_loot);
        
        return loot_1 > loot_2 ? loot_1 : loot_2;
        
    }
    
    int max(int a, int b) {
        return a > b ? a : b;
    }
    
};
