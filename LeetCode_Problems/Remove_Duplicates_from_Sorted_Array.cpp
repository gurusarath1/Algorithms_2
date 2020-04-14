/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j=0,i;
        
        for(i=0; i < nums.size() && j < nums.size(); i++)
        {
            nums[i] = nums[j];
            while(nums[i] == nums[j])
            {
                j++;
                
                if(j >= nums.size()) break;
            }   
        }
        
        return i;
    }
};
