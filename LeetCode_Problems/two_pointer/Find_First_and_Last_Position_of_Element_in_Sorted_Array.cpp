class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int ptr1 = 0;
        int ptr2 = nums.size() - 1;
        
        while(ptr1 <= ptr2) {
            
            if(nums[ptr1] == target && nums[ptr2] == target) {
                return vector<int>{ptr1, ptr2};
            } else if(nums[ptr1] == target) {
                ptr2--;
            } else if(nums[ptr2] == target) {
                ptr1++;
            } else {
                ptr1++;
                ptr2--;
            }
            
        }
        
        return vector<int>{-1,-1};
        
    }
};
