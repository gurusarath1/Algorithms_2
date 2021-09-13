class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first_index = -1, last_index = -1;
        
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        
        // Find first index
        while(start <= end) {
            
            mid = start + (end - start) / 2;
            
            if(nums[mid] >= target) {
                if(nums[mid] == target) first_index = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
            
        }
        
        if(first_index == -1) return vector<int>{-1,-1};
        
        // Find the last index
        start = first_index;
        end = nums.size() - 1;
        while(start <= end) {
            
            mid = start + (end - start) / 2;
            
            if(nums[mid] <= target) {
                if(nums[mid] == target) last_index = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            
        }
        
        return vector<int>{first_index, last_index};
        
    }
};
