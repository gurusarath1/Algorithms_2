class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start_index = 0;
        int end_index = nums.size() - 1;
        int mid_index;
        
        while(start_index <= end_index) {
            
            mid_index = start_index + (end_index - start_index)/2;
            
            if(nums[mid_index] == target) {
                return mid_index;
            } else if(nums[mid_index] > target) {
                end_index = mid_index - 1;
            } else {
                start_index = mid_index + 1;
            }
            
        }
        
        return -1;
        
    }
};
