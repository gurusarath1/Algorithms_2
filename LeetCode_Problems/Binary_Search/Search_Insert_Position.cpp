class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int high = nums.size() - 1;
        int low = 0;
        int mid;
        while(high >= low) {
            
            mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
            
        }
        
        return low;
        
    }
};
