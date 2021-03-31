class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 1 && nums[0] != target) return -1;
        if(nums.size() == 1 && nums[0] == target) return 0;
        
      
        /* FIND THE PIVOT */
        int left = 0;
        int right = nums.size() - 1;
        int mid = left + (right - left) / 2;;
        
        while(left < right) {
            if(nums[mid] > nums[right]) { // This is not normal in a sorted array
                left = mid + 1;
            } else { // This is normal
                right = mid;
            }
            mid = left + (right - left) / 2;
        }
        
        int pivot_index = mid; // This is also the smallest element
        
      
      
      /* SEARCH LEFT OR RIGHT */
        if(target > nums[nums.size() - 1]) {
            // search left half
            left = 0;
            right = pivot_index - 1;
        } else {
            // Search right half
            left = pivot_index;
            right = nums.size() - 1;
        }
        
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
        
    }
};
