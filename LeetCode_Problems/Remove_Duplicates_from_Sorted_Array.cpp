/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(unsigned int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
            {
                nums.erase(nums.begin() + i);
                i = i - 1;
            }
        }
        return nums.size();   
    }
};


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


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        int j=1;
        for(int i=1; i<nums.size(); i++) {
            
            if(nums[i-1] == nums[i]) {
                continue;
            }
            
            nums[j] = nums[i];
            j++;   
        }
        
        return j;
        
    }
};
