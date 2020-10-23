/*
Given an unsorted integer array nums, find the smallest missing positive integer.

Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space.?
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        if(nums.size() == 0) {
            return 1;
        }
        
        map<int,int> rec;
        
        for(auto val : nums) {
            rec[val] = 1;
        }
        
        for(int i=1; i<nums.size()+1; i++) {
            if(rec[i] == 0) {
                return i;
            }
        }
        
        return nums.size() + 1;
        
    }
};
